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

Node* makeTree(vector<int>&post,vector<int>&in,int start,int end,int &index,unordered_map<int,int>&mp){
    if(start>end){
        return NULL;
    }

    if(index<0) return NULL;

    int nextNode=post[index--];
    Node* root=new Node(nextNode);

    int i=mp[nextNode];
    root->right=makeTree(post,in,i+1,end,index,mp);
    root->left=makeTree(post,in,start,i-1,index,mp);
    

    return root;

    //------O(N) FOR SEARCHING 
    // for(int i=start;i<=end;i++){
    //     if(in[i]==root->data){
    //  
    //         root->right=makeTree(post,in,i+1,end,index,mp);
            //root->left=makeTree(post,in,start,i-1,index,mp);
    //     }
    // }

    return root;
}

int main(){
    // cout<<"Enter root value :-"<<endl;
    // Node* root=insert();
    // cout<<endl;
    // bfs(root);

    vector<int>post={10,7,6,8,100,35,12,4,2};
    vector<int>in={10,8,7,6,2,4,35,100,12};
    unordered_map<int,int>mp;
    for(int i=0;i<in.size();i++){
        mp[in[i]]=i;
    }
    int index=post.size()-1;
    Node*root=makeTree(post,in,0,in.size()-1,index,mp);
    bfs(root);
}