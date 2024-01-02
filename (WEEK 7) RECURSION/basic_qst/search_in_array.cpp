#include<bits/stdc++.h>
using namespace std;

int i=0;
bool search(int arr[],int n,int target){
   
    if(i>=n){
        return false;
    }
     if(target==arr[i++]){
        return true;
    }
    search(arr,n,target);
}

int main(){
    int arr[]={1,2,3,4,4};
    int n=5;
    int target=1;

    if(search(arr,n,target)){
        cout<<"FOUND"<<endl;
    }
    else{
        cout<<"NOT FOUND"<<endl;
    }
}