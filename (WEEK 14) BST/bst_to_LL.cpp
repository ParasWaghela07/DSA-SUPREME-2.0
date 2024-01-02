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
    return;
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



void createBst(Node* &root,vector<int>in){
    
    for(int i=0;i<in.size();i++){
        insertInBst(root,in[i]);
    }
}

void Inorder(Node* root,vector<int>&in){
    if(root==NULL){
        return;
    }

    Inorder(root->left,in);
    in.push_back(root->data);
    Inorder(root->right,in);
}
void Inorder2(Node* root,vector<Node*>&in){
    if(root==NULL){
        return;
    }

    Inorder2(root->left,in);
    in.push_back(root);
    Inorder2(root->right,in);
}

void solve(Node* root){
    if(root==NULL || (!root->left && !root->right) ) return;

    if(root->right){
        Node* temp=root->right;

        while(temp->left){
            temp=temp->left;
        }

        root->right=temp;
    }

    if(root->left){
    root->left->right=root;
    root->left->left=NULL;
    root->left=NULL;
    }

    solve(root->left);
    solve(root->right);

    
}

Node* makeLL(vector<Node*>in){
    Node* head=in[0];
    head->right=in[1];

    for(int i=1;i<in.size()-1;i++){
        in[i]->right=in[i+1];
    }

    in[in.size()-1]->right=NULL;

    return head;
}

void printList(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->right;
    }
}


//LAKSHAY BHAIYA'S SOLUTION

void Inorder3(Node* root,Node* &prev){
    if(root==NULL){
        return;
    }

    Inorder3(root->left,prev);
    prev->left=NULL;
    prev->right=root;
    prev=root;
    Inorder3(root->right,prev);
}

Node* flattenLL(Node* root){
    Node* dummy=new Node(-1);
    Node* prev=dummy;

    Inorder3(root,prev);
    prev->right=NULL;
    prev->left=NULL;
    root=dummy->right;

    return root;
}


int main(){

    // Node* root=NULL;
    // createBst(root);

    int inorder[]={8,5,1,7,10,12};
    sort(inorder,inorder+6);

    Node* root=bstbyinorder(inorder,0,5);

    /*vector<int>in;
    Inorder(root,in);

    Node* head=NULL;
    createBst(head,in);*/ //METHOD 1//


    /*vector<Node*>in;
    Inorder2(root,in);

    Node* head=makeLL(in);*/ //METHOD 2//
    
    // cout<<endl;
    // printList(head);



    //LAKSHAY BHAIYA'S SOLUTION

    Node* head=flattenLL(root);

    printList(head);


}