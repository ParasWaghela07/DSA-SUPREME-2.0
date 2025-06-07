#include<bits/stdc++.h>
using namespace std;

//TIME :- O(2^N) // RECURSION // INCLUDE //EXCLUDE // BACKTRACKING
//SPACE :- O(N) // RECURSION STACK OR TEMP ARRAY

void sos(int index,auto &v,auto &temp,auto &ans,int target){
    if(target<0) return;

    if(target==0){
        ans.push_back(temp);
        return;
    }

    for(int i=index;i<v.size();i++){
        temp.push_back(v[i]);
        sos(i+1,v,temp,ans,target-v[i]);
        temp.pop_back();
    }
}

int main(){
    vector<vector<int>>ans;
    vector<int>temp;

     vector<int>v={1, 9, 7, 5, 18, 12, 20, 15};
   int target=35;

   sos(0,v,temp,ans,target);

   for(int i=0;i<ans.size();i++){
    for(auto it:ans[i]){
        cout<<it<<" ";
    }
    cout<<endl;
   }

}