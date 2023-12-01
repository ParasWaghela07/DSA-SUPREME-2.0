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

void levelBfs(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* front=q.front();
        q.pop();

        if(front==NULL && !q.empty()){
            q.push(NULL);
            cout<<endl;
        }
        else{

        cout<<front->data<<" ";
        if((front->left)->data!=-1){
            q.push(front->left);
        }
        if((front->right)->data!=-1){
            q.push(front->right);
        }

        }

    }
}



int main(){
    cout<<"Enter the Root element : "<<endl;
    Node* root=InsertNode();
    
    cout<<"LEVEL WISE BFS : "<<endl;
    levelBfs(root);
    cout<<endl;

}