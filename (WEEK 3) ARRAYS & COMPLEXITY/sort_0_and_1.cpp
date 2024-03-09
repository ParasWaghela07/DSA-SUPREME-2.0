#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1,1,1,1,1,0,0,0,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    int i=0;
    int j=n-1;

    while(i<j){
        if(arr[i]==1){
            swap(arr[i],arr[j]);
            j--;
        }
        else{
            i++;
        }
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}