#include<bits/stdc++.h>
using namespace std;

int findfirstOcc(vector<int>&v,int &target){
    int s=0;
    int e=v.size()-1;
    int ans=-1;
    while(s<=e){
        int mid=s+(e-s)/2;

        if(v[mid]==target){
            ans=mid;
            e=mid-1;
        }
        else if(v[mid]>target){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }

    return ans;
}

int main(){
    vector<int>v={1,2,2,3,3,3,3};
    int target=5;
    int index=findfirstOcc(v,target);
    

    if(index==-1){
        cout<<"Not found"<<endl;
    }
    else{
        cout<<"Found at:"<<index<<endl;
    }
}