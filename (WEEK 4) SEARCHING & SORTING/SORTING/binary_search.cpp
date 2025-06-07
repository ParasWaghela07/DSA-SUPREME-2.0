#include<bits/stdc++.h>
using namespace std;
//TIME :- O(LOGN) //BEST CASE :- O(1)
//SPACE :- O(1) //DNC
int bs(auto &v,int s,int e,int &t){
    if(s>e){
        return -1;
    }

    int mid=s+(e-s)/2;

    if(v[mid]==t){
        return mid;
    }
    else if(v[mid]>t){
        return bs(v,s,mid-1,t);
    }
    else{
        return bs(v,mid+1,e,t);
    }
}

int main(){
    vector<int>v={1,2,5,6,7};
    int target=8;

    int index=bs(v,0,v.size()-1,target);
    if(index==-1){
        cout<<"NOT FOUND"<<endl;
    }
    else{
        cout<<"FOUND AT : "<<index<<endl;
    }
}