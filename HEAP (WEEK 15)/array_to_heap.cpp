
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


void ArrayToHeap(int arr[],int n){
    for(int index=n/2;index>0;index--){
        heapify(arr,n,index);
    }
}





int main(){
    int arr[]={-1,10,5,6,8,9,11,14};

    for(int i=1;i<=7;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    ArrayToHeap(arr,7);

    for(int i=1;i<=7;i++){
        cout<<arr[i]<<" ";
    }
}