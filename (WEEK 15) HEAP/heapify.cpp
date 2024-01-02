#include<bits/stdc++.h>
using namespace std;


void heapify(int arr[],int n,int index){
    int leftIndex=2*index;
    int rightIndex=(2*index) +1;
    int largestIndex=index;

    if(leftIndex<=n && arr[leftIndex]>arr[largestIndex]){
        largestIndex=leftIndex;
    }
    if(rightIndex<=n && arr[rightIndex]>arr[largestIndex]){
        largestIndex=rightIndex;
    }

    if(index==largestIndex){
        return;
    }
    swap(arr[largestIndex],arr[index]);
    heapify(arr,n,largestIndex);


}

int main(){
     int arr[]={-1,2,5,3};
    for(int i=1;i<4;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    heapify(arr,3,1);

    for(int i=1;i<4;i++){
        cout<<arr[i]<<" ";
    }
}