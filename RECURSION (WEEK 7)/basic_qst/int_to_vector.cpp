#include<bits/stdc++.h>
using namespace std;

void makevector(int n, vector<int>&ans){
    if(n==0){
        return;
    }
    makevector(n/10,ans);
    ans.push_back(n%10);
}

int main(){
    int num=150000;
    vector<int>ans;

    makevector(num,ans);

    for(auto it: ans){
        cout<<it<<"->";
    }
}