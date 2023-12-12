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

    Node* root=new Node(x);

    if(x==-1){
        return root;
    }
        cout<<"Enter the left value for :"<<root->data<<endl;
        root->left=InsertNode();
        cout<<"Enter the right value for :"<<root->data<<endl;
        root->right=InsertNode();
    
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
        }
        else{
            cout<<temp->data<<" ";

            if(temp->left->data!=-1){
                q.push(temp->left);
            }

            if(temp->right->data!=-1){
                q.push(temp->right);
            }
        }
    }
}

queue<Node*> rhsView(Node* root){
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

//USING RECURSION
void rhsByRecursion(Node* root,int level,vector<int>&v){
    if(root->data==-1){
        return;
    }

    if(level==v.size()){
        v.push_back(root->data);
    }

    rhsByRecursion(root->right,level+1,v);
    rhsByRecursion(root->left,level+1,v);
}

int main(){
    cout<<"Enter root : ";
    Node* root=InsertNode();

    // bfs(root);

//BY BFS METHOD 
    // queue<Node*>q1=rhsView(root);

    // while(!q1.empty()){
    //     Node* front=q1.front();
    //     q1.pop();

    //     if(q1.front()==NULL && !q1.empty())
    //     {
    //     cout<<front->data<<" ";
    //     q1.pop();
    //     }
    // }






    //BY RECURSION
    vector<int>v;
    rhsByRecursion(root,0,v);

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }

}