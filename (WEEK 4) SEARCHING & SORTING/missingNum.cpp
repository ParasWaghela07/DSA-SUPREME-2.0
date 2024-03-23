#include<bits/stdc++.h>
using namespace std;

int findMissing(vector<int>&v){
    int s=0;
    int e=v.size()-1;
    int ans=v.size();

    while(s<=e){
        int mid=s+(e-s)/2;
        if(v[mid]-mid==2){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }

    return ans+1;
}



int main(){
    vector<int>v={1,3,4,5,6,7,8,9};
    
    cout<<"Missing Number : "<<findMissing(v)<<endl;
}