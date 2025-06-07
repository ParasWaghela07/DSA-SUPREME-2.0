#include<bits/stdc++.h>
using namespace std;

//TIME :- O(N^2) // BEST:O(N) IF SORTED
//SPACE :- O(1) // SORTING

int main(){
    vector<int>v={3,1,5,7,3,2,0};

    for(int i=1;i<v.size();i++){
        int key=v[i];
        int j=i-1;
        while(j>=0 && v[j]>key){
            v[j+1]=v[j];
            j--;
        }

        v[j+1]=key;
    }

    for(auto it:v){
        cout<<it<<" ";
    }
}