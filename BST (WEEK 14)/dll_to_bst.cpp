#include<iostream>
#include<queue>

using namespace std;

class Node{
public:
int data;
Node* left;
Node* right;

Node(int val){
    this->data=val;
    this->left=NULL;
    this->right=NULL;
}
};

void insertInBst(Node* &root,int val){
    if(root==NULL){
        root=new Node(val);
        return;
    }
    
    if(root->data>val){
        insertInBst(root->left,val);
    }
    else{
        insertInBst(root->right,val);
    }
}



void createBst(Node* &root){
    int x;
    cout<<"Enter Data : ";
    cin>>x;

    while(x!=-1){
        insertInBst(root,x);
        cout<<"Enter Data : ";
        cin>>x;
    }
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


Node* dllTOBst(Node* &head,int n){
    if(head==NULL || n<=0){
        return NULL;
    }

    Node* leftAns=dllTOBst(head,n/2);

    Node* root=head;
    root->left=leftAns;
    head=head->right;

    Node* rightAns=dllTOBst(head,n-n/2-1);
    root->right=rightAns;

    return root;
}





int main(){

Node* first=new Node(10);
Node* second=new Node(20);
Node* third=new Node(30);

first->right=second;
second->left=first;

second->right=third;
third->left=second;

Node* head=first;

Node* root=dllTOBst(head,3);

levelOrderTraversal(root);

}