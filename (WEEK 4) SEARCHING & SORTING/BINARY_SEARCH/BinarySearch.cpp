#include<bits/stdc++.h>
using namespace std;

int findTarget(vector<int>&v,int &target){
    int s=0;
    int e=v.size()-1;
    while(s<=e){
        int mid=s+(e-s)/2;

        if(v[mid]==target){
            return mid;
        }
        else if(v[mid]>target){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }

    return -1;
}

int main(){
    vector<int>v={1,2,3,4,5,6,7};
    int target=10;
    int index=findTarget(v,target);
    

    if(index==-1){
        cout<<"Not found"<<endl;
    }
    else{
        cout<<"Found at:"<<index<<endl;
    }
}