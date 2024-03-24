#include<bits/stdc++.h>
using namespace std;

int getTargetIndex(int arr[],int &n,int &target){
    int s=0;
    int e=n-1;
    
    while(s<=e){
        int mid=s+(e-s)/2;\

        if(arr[mid]==target){
            return mid;
        }
        else if(mid+1 <n && arr[mid+1]==target){
            return mid+1;
        }
        else if(mid-1>=0 && arr[mid-1]==target){
            return mid-1;
        }
        else if(arr[mid]>target){
            e=mid-2;
        }
        else{
            s=mid+2;
        }
    }

    return -1;
}

int main(){
    int arr[]={20,10,30,50,40,70,60};
    int n=7;
    int target=100;

    int index=getTargetIndex(arr,n,target);

    if(index==-1){
        cout<<"Not found"<<endl;
    }
    else{
        cout<<"found at index : "<<index<<endl;
    }

}