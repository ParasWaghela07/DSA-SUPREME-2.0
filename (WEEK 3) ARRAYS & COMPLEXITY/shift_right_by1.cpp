#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int last=arr[n-1];

    for(int i=n-1;i>0;i--){
        arr[i]=arr[i-1];
    }

    arr[0]=last;

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}