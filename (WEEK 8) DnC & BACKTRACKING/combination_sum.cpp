class Solution {
public:
    void solve(vector<int>&c,int target,vector<int>temp,vector<vector<int>>&ans,int index){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(target<0){
            return;
        }

        while(index<c.size()){
            temp.push_back(c[index]);
            solve(c,target-c[index],temp,ans,index);
            temp.pop_back();
            index++;
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        int index=0;
        solve(candidates,target,temp,ans,index);

        return ans;
    }
};