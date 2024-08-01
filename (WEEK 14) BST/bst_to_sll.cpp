#include<bits/stdc++.h>
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



Node* bstbyinorder(vector<int>&inorder,int s,int e){
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




void printList(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        if(temp->left==NULL) cout<<" NULL HE ";
        temp=temp->right;
    }
}

void own(Node* root,Node* &head){
    if(!root) return;

    own(root->right,head);
    root->right=head;
    head=root;
    own(root->left,head);
    root->left=NULL;
}


int main(){
    Node* head=NULL;
    vector<int>inorder={10, 20, 30, 40, 50, 60, 65, 70, 80};
    Node* root=bstbyinorder(inorder,0,inorder.size()-1);
    levelOrderTraversal(root);
    own(root,head);

    cout<<"SORTED LIST : ";
    printList(head);
}