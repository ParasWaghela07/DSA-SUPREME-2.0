#include<bits/stdc++.h>
using namespace std;

void printSubArrays(int arr[],int n,int &s,int &e){
    if(e==n){
        s++;
        e=s;
    }
    if(s==n){
        return;
    }
    for(int i=s;i<=e;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    e++;
    printSubArrays(arr,n,s,e);
}
int main(){
    int arr[]={1,2,3,4,5};
    int n=5;
    int s=0;
    int e=0;
    printSubArrays(arr,n,s,e);
}