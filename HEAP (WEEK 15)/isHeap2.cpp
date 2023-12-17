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

class info{
    public:
    int maxVal;
    bool isHeap;

    info(int currVal,int truthVal){
        this->maxVal=currVal;
        this->isHeap=truthVal;
    }

};

info isHeap2(Node* root){
    if(root==NULL){
        info temp(INT_MIN,true);
        return temp;
    }
    if(root->left==NULL && root->right==NULL){
        info temp(root->data,true);
        return temp;
    }
    info leftAns=isHeap2(root->left);
    info rightAns=isHeap2(root->right);

    if(root->data > leftAns.maxVal && root->data > rightAns.maxVal && leftAns.isHeap && rightAns.isHeap){
        info temp(root->data,true);
        return temp;
    }
    else{
        int maxi=max(root->data,max(leftAns.maxVal,rightAns.maxVal));
        info temp(maxi,false);
        return temp;
    }
}



int main(){

    Node* root=InsertNode();
    levelOrderTraversal(root);

    info ans=isHeap2(root);
    if(ans.isHeap){
        cout<<"It is a Heap"<<endl;
        cout<<"MAX/ROOT VALUE : "<<ans.maxVal<<endl;
    }
    else{
        cout<<"It is not a Heap"<<endl;
        cout<<"EXPECTED MAX/ROOT VALUE : "<<ans.maxVal<<endl;
    }


}