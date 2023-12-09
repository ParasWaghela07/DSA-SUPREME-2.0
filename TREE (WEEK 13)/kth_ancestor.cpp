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

    Node* root=new Node(x);

    if(x==-1){
        return root;
    }
        cout<<"Enter the left value for :"<<root->data<<endl;
        root->left=InsertNode();
        cout<<"Enter the right value for :"<<root->data<<endl;
        root->right=InsertNode();
    
}

void kthAncestor(Node* root,Node* key,int &k,bool &flag, Node* &ans){

    if(root==NULL) return ;

    if(root==key){
        flag=true;
        return;
    }

    if(flag==true){
        k--;
        return;
    }

    kthAncestor(root->left,key,k,flag,ans);
    if(flag==true){
        k--;
        return;
    }
    if(k==0){
        ans=root;
    }
    kthAncestor(root->right,key,k,flag,ans);
    if(flag==true){
        k--;
        return;
    }
    if(k==0){
        ans=root;
    }

    if(k==0){
        ans=root;
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

    bool flag=false;
    Node* ans=new Node(NULL);
    kthAncestor(root,key,k,flag,ans);

    cout<<ans->data<<endl;


    
    

}