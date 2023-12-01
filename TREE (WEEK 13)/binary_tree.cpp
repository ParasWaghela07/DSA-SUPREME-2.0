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

void preorder(Node* root){
    if(root->data==-1){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root->data==-1){
        return;
    }

    inorder(root->left);

    cout<<root->data<<" ";

    inorder(root->right);
}

void postorder(Node* root){
    if(root->data==-1){
        return;
    }

    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    cout<<"Enter the Root element : "<<endl;
    Node* root=InsertNode();
    
    cout<<"PREORDER : ";
    preorder(root);
    cout<<endl;

    cout<<"INORDER : ";
    inorder(root);
    cout<<endl;

    cout<<"POSTORDER : ";
    postorder(root);
    cout<<endl;

}