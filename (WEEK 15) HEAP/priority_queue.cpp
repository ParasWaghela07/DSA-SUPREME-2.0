#include<iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int>pq; //MAX HEAP
    //priority_queue<int,vector<int>,greater<int>>pq; // MIN HEAP

    //insertion
    pq.push(10);
    pq.push(20);
    pq.push(50);
    //it stores value according to heapification

    cout<<"Top element of heap : "<<pq.top()<<endl;//MAX ELEMENT / ROOT ELEMENT IN MAX HEAP
    pq.pop(); //REMOVES MAX/ROOT ELEMENT AND TOP ELEMENTS GET UPDATED

    cout<<"Size : "<<pq.size()<<endl;

    if(pq.empty()){
        cout<<"Pq is empty"<<endl;
    }
    else{
        cout<<"Pq is not empty"<<endl;
    }
}