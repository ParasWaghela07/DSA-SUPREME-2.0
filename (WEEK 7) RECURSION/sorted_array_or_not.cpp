#include<bits/stdc++.h>
using namespace std;

void issorted(int arr[],int n,int&i,bool &ans){
    if(i>=n){
        return;
    }
    if(arr[i]<arr[i-1]){
        ans=false;
    }
    i++;

    issorted(arr,n,i,ans);
}

bool isSorted(int arr[],int n,int &i){ //another method
    if(i>=n){
        return true;
    }

    if(arr[i]>=arr[i-1]){
        i++;
        return isSorted(arr,n,i);
    }
    else{
        return false;
    }
}

int main(){
    int arr[]={1,21,14,42,58};
    int n=5;
    int i=1;
    bool ans=true;
    issorted(arr,n,i,ans);
    if(ans){
        cout<<"SORTED"<<endl;
    }
    else{
        cout<<"NOT-SORTED"<<endl;
    }
}