#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* InsertNode(){
    
    int x;
    cin>>x;

    if(x==-1){
        return NULL;
    }
        Node* root=new Node(x);
        cout<<"Enter the left value for :"<<root->data<<endl;
        root->left=InsertNode();
        cout<<"Enter the right value for :"<<root->data<<endl;
        root->right=InsertNode();
    
}

void bfs(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";

            if(temp->left!=NULL){
                q.push(temp->left);
            }

            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
    }
}

void top_view(Node* root){
    map<int,int>hdToNode;
    queue<pair<Node*,int>>q;

    q.push(make_pair(root,0));

    while(!q.empty()){
        auto front=q.front();
        q.pop();

        Node* Value=front.first;
        int Vlevel=front.second;

        if(hdToNode.find(Vlevel)==hdToNode.end()){ //checking for current Vertical level's entry is present or not , true=not present, false=present
        hdToNode[Vlevel]=Value->data;
        }

        if(Value->left!=NULL){
            q.push(make_pair(Value->left,Vlevel-1));
        }
        if(Value->right!=NULL){
            q.push(make_pair(Value->right,Vlevel+1));
        }
    }

    cout<<"TOP VIEW : ";
    for(auto i:hdToNode){
        cout<<i.second<<" ";
    }
}

int main(){
Node* root=InsertNode();

bfs(root);

top_view(root);
}