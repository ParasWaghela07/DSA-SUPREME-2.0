#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* right;
    Node* left;

    Node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* insert(){
    int x;
    cin>>x;
    if(x==-1){
        return NULL;
    }
    Node* root=new Node(x);
    cout<<"Insert left Value for "<<x<<endl;
    root->left=insert();

    cout<<"Insert right Value for "<<x<<endl;
    root->right=insert();

    return root;
}

void bfs(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* front=q.front();
        q.pop();

        if(front==NULL){
            if(q.empty()) break;
            else q.push(NULL);
            cout<<endl;
        }
        else{
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);

            cout<<front->data<<" ";
        }
    }
}

Node* makeTree(vector<int>&pre,vector<int>&in,int start,int end,int &index,unordered_map<int,int>&mp){
    if(start>end){
        return NULL;
    }

    int nextNode=pre[index++];
    Node* root=new Node(nextNode);

    int i=mp[nextNode];
    root->left=makeTree(pre,in,start,i-1,index,mp);
    root->right=makeTree(pre,in,i+1,end,index,mp);

    return root;

    //------O(N) FOR SEARCHING 
    // for(int i=start;i<=end;i++){
    //     if(in[i]==root->data){
    //         root->left=makeTree(pre,in,start,i-1,index);
    //         root->right=makeTree(pre,in,i+1,end,index);
    //     }
    // }

    return root;
}

int main(){
    // cout<<"Enter root value :-"<<endl;
    // Node* root=insert();
    // cout<<endl;
    // bfs(root);

    vector<int>pre={2,8,10,6,7,4,12,35,100};
    vector<int>in={10,8,7,6,2,4,35,100,12};
    unordered_map<int,int>mp;
    for(int i=0;i<in.size();i++){
        mp[in[i]]=i;
    }
    int index=0;
    Node*root=makeTree(pre,in,0,in.size()-1,index,mp);
    bfs(root);
}