#include<iostream>
#include<queue>
#include<vector>
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

        return root;
    
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
            else{
                break;
            }
        }
        else{
            cout<<temp->data<<" ";

            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}


//LEFT VIEW USING BFS
queue<Node*> lhsView(Node* root){
    queue<Node*>q;
    queue<Node*>q1;
    q.push(root);
    q.push(NULL);
    q1.push(root);
    q1.push(NULL);

    while(!q.empty()){

        Node* temp=q.front();
        q.pop();

        if(temp==NULL){
            if(!q.empty()){
                q.push(NULL);
                q1.push(NULL);
            }
        }
        else{

            if(temp->left->data!=-1){
                q.push(temp->left);
                q1.push(temp->left);
            }
            if(temp->right->data!=-1){
                q.push(temp->right);
                q1.push(temp->right);
            }

        }
    

    }

    return q1;
}

void leftview(Node*root){
    queue<Node*>q;
    q.push(root);
    cout<<root->data<<endl;
    q.push(NULL);

    while(!q.empty()){
        Node*front=q.front();
        q.pop();

        if(front==NULL){
            if(q.empty()) break;
            q.push(NULL);
            cout<<q.front()->data<<endl;
        }
        else{
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }

    }
}

//USING RECURSION
void lhsByRecursion(Node* root,int level,vector<int>&v){
    if(root->data==-1){
        return;
    }

    if(level==v.size()){
        v.push_back(root->data);
    }

    lhsByRecursion(root->left,level+1,v);
    lhsByRecursion(root->right,level+1,v);
}


int main(){
    cout<<"Enter root : ";
    Node* root=InsertNode();

    bfs(root);
    cout<<"LHS "<<endl;
    //BY BFS METHOD 

    // queue<Node*>q1=lhsView(root);

    // cout<<"LEFT VIEW : ";

    // while(!q1.empty()){
    //     Node* front=q1.front();
    //     cout<<front->data<<" ";
    //     q1.pop();

    //     while(q1.front()!=NULL){
    //         q1.pop();
    //     }

    //     if(q1.front()==NULL && !q1.empty())
    //     q1.pop();
    // }

    leftview(root);





    //BY RECURSION
    vector<int>v;
    lhsByRecursion(root,0,v);

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }

}