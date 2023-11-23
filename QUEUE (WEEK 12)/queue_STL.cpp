#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int>q;

    q.push(5);

    cout<<"Size : "<<q.size()<<endl;

    if(q.empty()){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }

    q.pop();
    cout<<"Size : "<<q.size()<<endl;

    if(q.empty()){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }

    q.push(10);
    q.push(20);
    q.push(30);

    cout<<"First : "<<q.front()<<endl;
    cout<<"Last : "<<q.back()<<endl;
}