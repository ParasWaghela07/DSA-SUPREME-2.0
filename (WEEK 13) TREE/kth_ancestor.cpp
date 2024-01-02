#include<iostream>
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

Node* kthAncestor(Node* root,Node* key,int &k,int &ans){
    if(root==NULL){
        return NULL;
    }

    if(ans!=-1){
        return root;
    }

    if(root->data==key->data){
        return root;
    }

    Node* leftAns=kthAncestor(root->left,key,k,ans);
    Node* rightAns=kthAncestor(root->right,key,k,ans);

    if(leftAns==NULL && rightAns==NULL){
        return NULL;
    }

    k--;
    if(k==0){
        ans=root->data;
        return root;
    }

    if(leftAns!=NULL && rightAns==NULL){
        return leftAns;
    }
    else if(leftAns==NULL && rightAns!=NULL){
        return rightAns;
    }
    else{
        return root;
    }
}

int main(){
    cout<<"Enter the Root element : "<<endl;
    Node* root=InsertNode();

    cout<<"Enter the Node of which ancestor you want to find : ";
    int x;
    cin>>x;
    cout<<"Enter the value of K : ";
    int k;
    cin>>k;

    Node* key=new Node(x);

    int ans=-1;
    kthAncestor(root,key,k,ans);

    cout<<ans<<endl;

}