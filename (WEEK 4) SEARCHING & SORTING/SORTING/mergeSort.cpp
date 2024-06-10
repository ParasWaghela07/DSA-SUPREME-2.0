#include<bits/stdc++.h>
using namespace std;

//TIME :- O(NLOGN) // DNC
//SPACE :- O(N) // TEMP ARRAYS

void merge(vector<int>&v,int s,int e,int mid){
    vector<int>temp=v;

    int k=s;
    int i=s;
    int j=mid+1;

    while(i<=mid && j<=e){
        if(temp[i]<temp[j]){
            v[k]=temp[i];
            k++;
            i++;
        }
        else{
            v[k]=temp[j];
            k++;
            j++;
        }
    }

    while(i<=mid){
            v[k]=temp[i];
            k++;
            i++;
    }

    while(j<=e){
            v[k]=temp[j];
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