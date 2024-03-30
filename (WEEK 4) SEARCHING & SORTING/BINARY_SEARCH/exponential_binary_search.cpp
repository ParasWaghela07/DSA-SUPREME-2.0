//WORKS FOR LARGE INPUT ARRAY , TC:- 2^LOG(M-1) , M IS THE INDEX AFTER WHILE LOOP IN MAIN

#include<bits/stdc++.h>
using namespace std;

int search(vector<int>&v,int s,int e,int x){
    while(s<=e){
        int mid=s+(e-s)/2;

        if(v[mid]==x){
            return mid;
        }
        else if(v[mid]>x){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }

    return -1;
}

int main(){
    vector<int>v={1,2,3,4,5,6,7,7,8,10};
    int target=2;

    if(v[0]==target){
        cout<<"At index:"<<0<<endl;
    }
    else{
        int index=1;
        while(index<v.size() && v[index]<target){
            index=index*2;
        }
        int n=v.size();
        cout<<search(v,index/2,min(n-1,index),target)<<endl;
    }
}