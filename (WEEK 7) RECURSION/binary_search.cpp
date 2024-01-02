#include<bits/stdc++.h>
using namespace std;


bool search(int arr[],int n,int target,int s,int e){
   if(s>e){
    return false;
   }
   int mid=s+(e-s)/2;
   if(arr[mid]==target){
    return true;
   }
   else if(arr[mid]>target){
    return search(arr,n,target,s,mid-1);
   }
   else{
    return search(arr,n,target,mid+1,e);
   }
}

int searchIndex(int arr[],int n,int target,int s,int e){ //return index
   if(s>e){
    return -1;
   }
   int mid=s+(e-s)/2;
   if(arr[mid]==target){
    return mid;
   }
   else if(arr[mid]>target){
    return searchIndex(arr,n,target,s,mid-1);
   }
   else{
    return searchIndex(arr,n,target,mid+1,e);
   }
}

int main(){
    int arr[]={1,2,3,4,4};
    int n=1;
    int s=0;
    int e=n-1;
    int target=3;

    if(search(arr,n,target,s,e)){
        cout<<"FOUND"<<endl;
    }
    else{
        cout<<"NOT FOUND"<<endl;
    }
}