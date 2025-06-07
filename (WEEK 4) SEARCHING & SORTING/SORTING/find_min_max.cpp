#include<bits/stdc++.h>
using namespace std;
//TIME :- O(N) //DNC
//SPACE :- O(1) //RECURSION STACK SPACE !

void findminmax(vector<int>&v,int s,int e,int &mini,int &maxi){
    if(s>e){
        return;
    }
    if(s==e){
        mini=min(mini,v[s]);
        maxi=max(maxi,v[s]);
        return;
    }

    int mid=s+(e-s)/2;
    findminmax(v,s,mid,mini,maxi);
    findminmax(v,mid+1,e,mini,maxi);
}


int main(){
    vector<int>v={3,1,5,-7,3,2,0};

    int mini=INT_MAX;
    int maxi=INT_MIN;
    findminmax(v,0,v.size()-1,mini,maxi);
    cout<<"MIN:"<<mini<<endl;
    cout<<"MAX:"<<maxi<<endl;
}