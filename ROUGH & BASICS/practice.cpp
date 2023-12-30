#include<bits/stdc++.h>
using namespace std;

class heap{
    public:

    int *arr;
    int size;
    int capacity;

    heap(int size){
        this->arr=new int[size];
        this->size=0;
        this->capacity=size;
    }

    void insert(int x){
        if(size==capacity){
            cout<<"OVERFLOW"<<endl;
        }
        int index=size;
        size++;
        arr[index]=x;

        while(index>0){
            int parentIndex=(index-1)/2;

            if(arr[index]>arr[parentIndex]){
                swap(arr[index],arr[parentIndex]);
                index=parentIndex;
            }
            else{
                break;
            }
        }
    }

    void deleteTop(){
        arr[0]=arr[size-1];
        size--;
        int index=0;

        while(index<size){
            int leftIndex=(2*index)+1;
            int rightIndex=(2*index)+2;
            int largestIndex=index;

            if(leftIndex<size && arr[leftIndex] > arr[largestIndex]){
                largestIndex=leftIndex;
            }
            if(rightIndex<size && arr[rightIndex] > arr[largestIndex]){
                largestIndex=rightIndex;
            }

            if(index==largestIndex){
                break;
            }
            else{
                swap(arr[index],arr[largestIndex]);
                index=largestIndex;
            }
        }
    }

    void printHeap(){
        cout<<"size :- "<<size<<endl;
        for(int i=0;i<size;i++){
            cout<<i<<"->"<<arr[i]<<endl;
        }
    }
};

void heapify(int arr[],int size,int index){
    int leftIndex=(2*index)+1;
    int rightIndex=(2*index)+2;
    int largestIndex=index;

     if(leftIndex<size && arr[leftIndex] > arr[largestIndex]){
                largestIndex=leftIndex;
            }
            if(rightIndex<size && arr[rightIndex] > arr[largestIndex]){
                largestIndex=rightIndex;
            }

            if(index==largestIndex){
                return;
            }
            else{
                swap(arr[index],arr[largestIndex]);
                index=largestIndex;
                heapify(arr,size,index);
            }
}

void ArrayToHeap(int arr[],int size){
    for(int i=(size/2)-1;i>=0;i--){
        heapify(arr,size,i);
    }
}

void heapSort(int arr[],int n){
    while(n!=0){
        swap(arr[0],arr[n-1]);
        n--;
        heapify(arr,n,0);
    }
}

int main(){
    heap h(5);
    h.insert(1);
    h.insert(2);
    h.insert(3);
    h.insert(4);
    h.insert(5);

    // h.deleteTop();

    h.printHeap();

    int arr[]={1,2,3,4,5};
    int size=5;

    ArrayToHeap(arr,5);

    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }



}