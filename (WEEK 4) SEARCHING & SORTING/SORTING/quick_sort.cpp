#include<bits/stdc++.h>
using namespace std;

//TIME :- O(NLOGN) // PARTITION AND MERGING // DNC //WORST CASE :- O(N^2) //DUE TO ALREADY SORTED PARTITIONS EACH ELEMENT
//SPACE :- O(1) // 

void quicksort(vector<int>&v,int s,int e){
    if(s>=e){
        return;
    }

    int i=s-1;
    int j=s;
    int pivot=e;

    while(j<pivot){
        if(v[j]<v[pivot]){
            i++;
            swap(v[i],v[j]);
            j++;
        }
        else{
            j++;
        }
    }

    i++;
    swap(v[i],v[pivot]);

    quicksort(v,s,i-1);
    quicksort(v,i+1,e);
}


int main(){
    vector<int>v={3,1,5,-7,3,2,0};

    quicksort(v,0,v.size()-1);
    for(auto it:v){
        cout<<it<<" ";
    }
}