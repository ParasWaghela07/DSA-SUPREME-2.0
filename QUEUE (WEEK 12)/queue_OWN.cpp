#include<iostream>
using namespace std;

class Queue{
    public:
    int rear;
    int front;
    int* arr;
    int size;

    Queue(int size){
        arr=new int[size];
        this->size=size;
        rear=-1;
        front=-1;
    }

    void push(int data){

        if(rear==size-1){
            cout<<"OVERFLOW\n";
        }
        else if(rear == -1 && front==-1){   //entering 1st element in empty queue 
            front++;
            rear++;
            arr[rear]=data;
        }
        else{
            rear++;
            arr[rear]=data;
        }
    }

    void pop(){
        if(front==-1 && rear==-1 ){
            cout<<"UNDERFLOW\n";
        }
        else if(front==rear){
            arr[front]=-1;
            front=-1;
            rear=-1;
        }
        else{
            arr[front]=-1;
            front++;
        }
    }

    bool isEmpty(){
        if(front==-1 && rear==-1 ){
            return true;
        }
        else{
            return false;
        }
    }

    int getsize(){
        if(front==-1 && rear==-1){
            return 0;
        }
        return rear-front+1;
    }

    int getlastElement(){
        if(rear!=-1 && rear<size)
        return arr[rear];
        else
        return -1;
    }

    int getFirstElement(){
        if(front!=-1 && front<size)
        return arr[front];
        else
        return -1;
    }

    void print(){
        
            for(int i=0;i<size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        
    }
};

int main(){
    Queue q(5);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    q.pop();
    q.push(100);
    
    
    


}