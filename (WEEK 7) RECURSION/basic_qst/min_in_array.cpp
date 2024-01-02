#include<bits/stdc++.h>
using namespace std;

int i=0;
void minimum(int arr[],int n,int &mini){
    if(i>=n){
        return;
    }
    if(arr[i]<mini){
        mini=arr[i];
    }
    i++;
    minimum(arr,n,mini);
}

int main(){
    int arr[]={1,2,3,4,4,0};
    int n=6;
    int mini=INT_MAX;

    minimum(arr,n,mini);
    cout<<mini<<endl;
}