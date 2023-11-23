#include<bits/stdc++.h>
using namespace std;

void merge(queue<int>&q){
    queue<int>qn;
    int size=q.size();

    if(size%2==0){
        for(int i=0;i<size/2;i++){
        int temp=q.front();
        q.pop();

        qn.push(temp);
    }

    for(int i=0;i<size/2;i++){
        int temp=qn.front();
        qn.pop();

        q.push(temp);

        temp=q.front();
        q.pop();
        q.push(temp);
    }
    }
    else{
        for(int i=0;i<(size/2)+1;i++){
        int temp=q.front();
        q.pop();

        qn.push(temp);
    }

    for(int i=0;i<(size/2);i++){
        int temp=qn.front();
        qn.pop();

        q.push(temp);

        temp=q.front();
        q.pop();
        q.push(temp);
    }
    int temp=qn.front();
    qn.pop();
    q.push(temp);
    }

    
}

int main(){
    queue<int>q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    // q.push(7);

    merge(q);

    while(q.empty()==0){
        cout<<q.front()<<" ";
        q.pop();
    }

    cout<<endl;
}