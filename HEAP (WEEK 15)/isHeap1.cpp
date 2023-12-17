#include<iostream>
#include<queue>
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

void levelOrderTraversal(Node* &root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node *front=q.front();
        q.pop();

        if(front==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<front->data<<" ";

            if(front->left!=NULL ){
                q.push(front->left);
            }
            if(front->right!=NULL){
                q.push(front->right);
            }
        }
    }
}


bool isHeap(Node* root){
    if(root==NULL){
        return true;
    }
    if(root->left==NULL && root->right==NULL){
        return true;
    }

    bool leftAns=isHeap(root->left);
    bool rightAns=isHeap(root->right);

    if( leftAns && rightAns){
        if(root->left && (root->data < root->left->data)){
            return false;
        }
        if(root->right && (root->data < root->right->data)){
            return false;
        }
        return true;
    }
    else{
        return false;
    }
}


int main(){

    Node* root=InsertNode();
    levelOrderTraversal(root);

    bool ans=isHeap(root);
    if(ans){
        cout<<"Valid Max Heap"<<endl;
    }
    else{
        cout<<"Not a valid max heap"<<endl;
    }



}