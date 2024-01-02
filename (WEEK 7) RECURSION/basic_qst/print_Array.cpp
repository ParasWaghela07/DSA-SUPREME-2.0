#include<bits/stdc++.h>
using namespace std;

int i=0;
void printArray(int arr[],int n){
    if(i>=n){
        return;
    }
    cout<<arr[i++]<<" ";
    printArray(arr,n);
}

int main(){
    int arr[]={1,2,3,4,4};
    int n=5;

    printArray(arr,n);
}