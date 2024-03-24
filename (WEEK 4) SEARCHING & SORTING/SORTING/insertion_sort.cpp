#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={55,4,33,2,11};
    int n=5;

    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(arr[j]>key && j>=0){
            arr[j+1]=arr[j];
            j--;
        }

        arr[j+1]=key;
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}