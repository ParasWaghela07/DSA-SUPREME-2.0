#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={55,4,33,2,11};
    int n=5;

    for(int i=0;i<n-1;i++){
        int mini=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[mini]){
                mini=j;
            }
        }
        swap(arr[i],arr[mini]);
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}