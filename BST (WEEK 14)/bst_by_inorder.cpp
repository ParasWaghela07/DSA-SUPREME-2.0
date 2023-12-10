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

Node* bstbyinorder(int inorder[],int s,int e){
    if(s>e){
        return NULL;
    }

    int mid=s+(e-s)/2;
    int element=inorder[mid];
    Node* root=new Node(element);

    root->left=bstbyinorder(inorder,s,mid-1);
    root->right=bstbyinorder(inorder,mid+1,e);

    return root;
}

void Inorder(Node* root){
    if(root==NULL){
        return;
    }

    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}


int main(){

    // Node* root=NULL;
    // createBst(root);

    int inorder[]={10,20,30,40,50,60};

    Node* root=bstbyinorder(inorder,0,5);

    levelOrderTraversal(root);
    cout<<"Inorder : ";

    Inorder(root);
    
    cout<<endl;

}