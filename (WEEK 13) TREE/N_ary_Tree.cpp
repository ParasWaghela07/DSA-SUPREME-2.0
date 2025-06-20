#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
    public:
    vector<Node*>c;
    int size;
    int val;
    
    Node(int size,int data){
        this->size=size;
        this->c.resize(size);
        this->val=data;
    }
};

Node* InsertNode(){

    int data;
    cout<<"Enter the value of the node : ";
    cin>>data;

    int size;
    cout<<"Enter the size of the node : ";
    cin>>size;
    
    Node* newNode=new Node(size,data);
    
    cout<<"Enter the elements of the node : ";
    for(int i=0;i<size;i++){
        newNode->c[i]=InsertNode();
    }
    return newNode;
}

void bfs(Node*root){
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        while(size--){
            Node* current=q.front();
            q.pop();
            cout<<current->val<<" ";
            
            for(int i=0;i<current->size;i++){
                q.push(current->c[i]);
            }
        }
        cout<<endl;
    }
}

int main(){
    cout<<"Enter the Root element : "<<endl;
    Node* root=InsertNode();
    cout<<"Tree created successfully!"<<endl;
    bfs(root);
}