#include<iostream>
#include<queue>
using namespace std;

int kthMaximum(int arr[],int n,int k){
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }

    for(int i=k;i<n;i++){
        if(arr[i]>pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
}

int main(){
    int arr[]={4,2,7,1,6,9};
    int n=6;
    int k=1;
    int ans=kthMaximum(arr,n,k);

    cout<<k<<"th Maximum element : "<<ans<<endl;
}