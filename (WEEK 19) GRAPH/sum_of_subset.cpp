#include<bits/stdc++.h>
using namespace std;

void SumofSubset(int index,vector<int>&v,int sum,vector<int>&temp,vector<vector<int>>&ans){
    if(sum==0){
        ans.push_back(temp);
        return;
    }
    if(sum<0){
        return;
    }

    for(int i=index;i<v.size();i++){
        temp.push_back(v[i]);
        SumofSubset(i+1,v,sum-v[i],temp,ans);
        temp.pop_back();
    }


}

int main(){
    vector<int>v={1, 9, 7, 5, 18, 12, 20, 15};
    int sum=35;

    vector<int>temp;
    vector<vector<int>>ans;

    SumofSubset(0,v,sum,temp,ans);

    for(int i=0;i<ans.size();i++){
        cout<<"{";
        for(auto it:ans[i]){
            cout<<it<<" ,";
        }
        cout<<"}"<<endl;

    }

}