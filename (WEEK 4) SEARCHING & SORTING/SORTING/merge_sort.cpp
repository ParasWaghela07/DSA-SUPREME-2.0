#include<bits/stdc++.h>
using namespace std;

//TIME :- O(NLOGN) // DNC
//SPACE :- O(N) // TEMP ARRAYS

void merge(vector<int>&v,int s,int e,int mid){
    vector<int>left;
    vector<int>right;

    for(int i=s;i<=mid;i++){
        left.push_back(v[i]);
    }

    for(int i=mid+1;i<=e;i++){
        right.push_back(v[i]);
    }

    int k=s;
    int i=0;
    int j=0;

    while(i<left.size() && j<right.size()){
        if(left[i]<right[j]){
            v[k]=left[i];
            k++;
            i++;
        }
        else{
            v[k]=right[j];
            k++;
            j++;
        }
    }

    while(i<left.size()){
            v[k]=left[i];
            k++;
            i++;
    }

    while(j<left.size()){
            v[k]=right[j];
            k++;
            j++;
    }

}

void mergesort(vector<int>&v,int s,int e){
    if(s>=e){
        return;
    }

    int mid=s+(e-s)/2;
    mergesort(v,s,mid);
    mergesort(v,mid+1,e);
    merge(v,s,e,mid);
}

int main(){
    vector<int>v={3,1,5,7,3,2,0};

    mergesort(v,0,v.size()-1);
    for(auto it:v){
        cout<<it<<" ";
    }
}