#include<bits/stdc++.h>
using namespace std;

void FirstNegative(int arr[],int k,int size){
    queue<int>q;

    for(int i=0;i<k;i++){
        if(arr[i]<0){
            q.push(i);
        }
    }

    for(int i=k;i<size;i++){
        if(q.empty()){
            cout<<0<<" ";
        }
        else{
            cout<<arr[q.front()]<<" ";
        }

        if(!q.empty() && i-q.front()>=k){
            q.pop();
        }

        if(arr[i]<0){
                q.push(i);
        }
    }

    if(q.empty()){
            cout<<0<<" ";
        }
        else{
            cout<<arr[q.front()]<<" ";
        }
}

int main(){
    int arr[]={1,2,3,-5,4,3,-2};
    int k=3;
    int size=7;

    FirstNegative(arr,k,size);
}