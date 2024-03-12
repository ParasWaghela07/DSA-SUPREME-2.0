#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>v={4,3,2,6};
    int n=v.size();

    priority_queue<int,vector<int>,greater<int>>pq;
    int cost=0;

    for(auto it:v){
        pq.push(it);
    }

    while(pq.size()>1){
        int a=pq.top(); pq.pop();
        int b=pq.top(); pq.pop();

        int c = a+b;
        cost+=c;
        pq.push(c);
    }

    cout<<"cost:- "<<cost<<endl;
}