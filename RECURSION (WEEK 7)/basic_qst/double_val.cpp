#include<bits/stdc++.h>
using namespace std;

int i=0;
void mby2(int arr[],int n){
    if(i>=n){
        return;
    }
    arr[i]=arr[i]*2;
    i++;
    mby2(arr,n);
}

int main(){
    int arr[]={1,2,3,4,4,0};
    int n=6;
    mby2(arr,n);

    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
}