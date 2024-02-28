class Solution {
public:
//LAKSHAY BHAIYA
void solve(vector<int>&c,int target,vector<int>temp,vector<vector<int>>&ans,int index){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(target<0){
            return;
        }

        for(int i=index;i<c.size();i++){

            if(i>index && c[i]==c[i-1]) continue;

            temp.push_back(c[i]);
            solve(c,target-c[i],temp,ans,i+1);
            temp.pop_back();
        }
    }

    //MINE
void solve(vector<int>&c,int target,vector<int>temp,vector<vector<int>>&ans,int index){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(target<0 || index>=c.size()){
            return;
        }

        while(index<c.size()){
            int curr=c[index];
            temp.push_back(c[index]);
            solve(c,target-c[index],temp,ans,index+1);
            temp.pop_back();

            while(index<c.size() && c[index]==curr)
            index++;

        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;
        int index=0;
        solve(candidates,target,temp,ans,index);

        return ans;
    }
};