#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
    int *arr;
    int size;
    int capacity;

    heap(int size){
        this->arr=new int[size+1];
        this->size=0;
        this->capacity=size;
   }

   void insert(int data){
    if(size==capacity){
        cout<<"Heap overflow"<<endl;
        return;
    }
    else{
        size++;
        int index=size;
        arr[index]=data;

        while(index>1){
            int parentIndex=index/2;
            if(arr[index]>arr[parentIndex]){
                swap(arr[parentIndex],arr[index]);
                index=parentIndex;
            }
            else{
                break;
            }
        }
    }
}

void deleteFromHeap(){
    int ans=arr[1];
    arr[1]=arr[size];
    size--;


    int index=1;
    while(index<size){

    
    int leftIndex=2*index;
    int rightIndex=(2*index)+1;

    int largestIndex=index;

    if(leftIndex<=size && arr[leftIndex]>arr[largestIndex]){
        largestIndex=leftIndex;
    }
    if(rightIndex<=size && arr[rightIndex]>arr[largestIndex]){
        largestIndex=rightIndex;
    }

    if(index==largestIndex){
        break;
    }
    else{
        swap(arr[largestIndex],arr[index]);
        index=largestIndex;
    }

    }
}

void printHeap(){
    for(int i=1;i<=size;i++){
        cout<<arr[i]<<" ";
    }
}
};

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

void heapSort(int arr[],int n){
    while(n!=1){
        swap(arr[1],arr[n]);
        n--;
        heapify(arr,n,1);
    }
}

int main(){
    heap h(3);

    // h.insert(10);
    // h.insert(5);
    // h.insert(6);
    // h.insert(8);
    // // h.insert(9);
    // // h.insert(11);
    // // h.insert(14);


    // h.printHeap();
    // cout<<endl;
    // h.deleteFromHeap();
    // h.printHeap();



    // int arr[]={-1,2,5,3};
    // for(int i=1;i<4;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    // heapify(arr,3,1);

    // for(int i=1;i<4;i++){
    //     cout<<arr[i]<<" ";
    // }

    int arr[]={-1,10,5,6,8,9,11,14};

    for(int i=1;i<=7;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    ArrayToHeap(arr,7);

    for(int i=1;i<=7;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    heapSort(arr,7);
    for(int i=1;i<=7;i++){
        cout<<arr[i]<<" ";
    }


}





