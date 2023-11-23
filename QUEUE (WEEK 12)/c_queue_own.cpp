#include<iostream>
using namespace std;

class Cqueue{
    public:
    int rear;
    int front;
    int size;
    int* arr;

    Cqueue(int size){
        rear=-1;
        front=-1;
        arr=new int[size];
        this->size=size;
    }

    void push(int data){
        if(rear==size-1 && front==0){
            cout<<"OVERFLOW\n";
        }
        else if(rear+1==front){
            cout<<"OVERFLOW\n";
        }
        else if(rear==-1 && front ==-1){
            front++;
            rear++;
            arr[rear]=data;
        }
        else if(rear==size-1){
            rear=0;
            arr[rear]=data;
        }
        else{
            rear++;
            arr[rear]=data;
        }
    }

    void pop(){
        if(front==-1 && rear==-1){
            cout<<"UNDERFLOW\n";
        }
        else if(front==rear){
            arr[front]=-1;
            front=-1;
            rear=-1;
        }
        else if(front==size-1){
            arr[front]=-1;
            front=0;
        }
        else{
            arr[front]=-1;
            front++;
        }
    }

    void print(){
        
            for(int i=0;i<size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        
    }

};

int main(){
    Cqueue cq(5);

    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.push(4);
    cq.push(5);

    cq.pop();
    cq.pop();
    cq.pop();

    cq.push(4);
    cq.push(5);
    cq.push(5);

    cq.pop();
    cq.pop();
    cq.pop();
    cq.pop();
    cq.pop();
    

    cq.push(5);

    cq.print();
}