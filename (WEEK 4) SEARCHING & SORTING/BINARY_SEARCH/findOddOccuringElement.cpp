#include<bits/stdc++.h>
using namespace std;

int findOddOccuringElement(int arr[],int n){
    int s=0;
    int e=n-1;

    while(s<=e){
        int mid=s+(e-s)/2;

        if(s==e) return s;

        if(mid&1){
            if(mid-1>=0 && arr[mid]==arr[mid-1]){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        else{
            if(mid+1<n && arr[mid]==arr[mid+1]){
                s=mid+2;
            }
            else{
                e=mid;
            }
        }
    }

    return -1;
}



int main(){
    int arr[]={1,1,5,5,2,2,3,3,2,4,4};
    int n=11;
    int ans=findOddOccuringElement(arr,n);
    cout<<"Odd occuring element is: "<<arr[ans]<<endl;
}