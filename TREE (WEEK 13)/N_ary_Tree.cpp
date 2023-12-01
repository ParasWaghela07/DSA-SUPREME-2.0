#include<iostream>
using namespace std;

class Node{
    public:
    int* arr;
    int size;
    

    Node(int size){
        this->size=size;
        arr=new int[size];
    }
};

Node* InsertNode(){
    
}


int main(){
    cout<<"Enter the Root element : "<<endl;
    Node* root=InsertNode();
    
    

}