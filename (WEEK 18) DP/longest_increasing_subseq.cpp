class Solution {
public:
    int byRecursion(vector<int>&nums,int prev,int curr){
        if(curr>=nums.size()){
            return 0;
        }
        int include=0;
        if(prev==-1 || nums[prev] < nums[curr]){
            include = 1 + byRecursion(nums,curr,curr+1);
        }
        int exclude = 0 + byRecursion(nums,prev,curr+1);

        return max(include,exclude);
    }

    int byMemoisation(vector<int>&nums,int prev,int curr,vector<vector<int>>&dp){
        if(curr>=nums.size()){
            return 0;
        }
        if(dp[curr][prev+1]!=0){
            return dp[prev+1][curr];
        }
        int include=0;
        if(prev==-1 || nums[prev] < nums[curr]){
            include = 1 + byMemoisation(nums,curr,curr+1,dp);
        }
        int exclude = 0 + byMemoisation(nums,prev,curr+1,dp);

        dp[curr][prev+1]=max(include,exclude);
        return  dp[curr][prev+1];
    }

    int ByTabu(vector<int>&nums,vector<vector<int>> &dp){
        for(int curr=nums.size()-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int include=0;
            if(prev==-1 || nums[prev] < nums[curr]){
                include = 1 + dp[curr+1][curr+1];
            }
            int exclude = 0 + dp[curr+1][prev+1];

            dp[curr][prev+1]=max(include,exclude);
            }
        }

        return dp[0][0];
    }

    int byTabuSO(vector<int>&nums){
        vector<int>currRow(nums.size()+1,0);
        vector<int>nextRow(nums.size()+1,0);

        for(int curr=nums.size()-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int include=0;
            if(prev==-1 || nums[prev] < nums[curr]){
                include = 1 + nextRow[curr+1];
            }
            int exclude = 0 + nextRow[prev+1];

            currRow[prev+1]=max(include,exclude);
            }
            nextRow=currRow;
        }

        return nextRow[0];
    }

    int byBS(vector<int>&nums){
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                int index=lower_bound(ans.begin(),ans.end(),nums[i]) - ans.begin();
                ans[index]=nums[i];
            }
        }
        return ans.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        int prev=-1;
        int curr=0;

        int ans=byRecursion(nums,prev,curr);
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,0));

        int ans = byMemoisation(nums,prev,curr,dp);
        int ans = ByTabu(nums,dp);
        int ans = byTabuSO(nums);

        int ans=byBS(nums);
        return ans;
    }
};