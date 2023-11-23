#include<bits/stdc++.h>
using namespace std;

void reverse(queue<int>&q){
    //STACK METHOD

    // stack<int>st;

    // while(q.empty()==0){
    //     st.push(q.front());
    //     q.pop();
    // }

    // while(st.empty()==0){
    //     q.push(st.top());
    //     st.pop();
    // }

    //RECURSIVE METHOD

    if(q.empty()){
        return;
    }

    int temp=q.front();
    q.pop();
    reverse(q);
    q.push(temp);
}

int main(){
    queue<int>q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    reverse(q);

    while(q.empty()==0){
        cout<<q.front()<<" ";
        q.pop();
    }

    cout<<endl;
}