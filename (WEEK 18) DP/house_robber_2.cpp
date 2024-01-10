class Solution {
public:
    int byRecursion(vector<int>&nums,int i,vector<int>&dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int op1=nums[i]+byRecursion(nums,i+2,dp);
        int op2= 0 + byRecursion(nums,i+1,dp);

        dp[i] =  max(op1,op2);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int>dp1(nums.size(),-1);
        vector<int>dp2(nums.size(),-1);
        int ans1=byRecursion(nums,1,dp1);
        nums.pop_back();
        int ans2=byRecursion(nums,0,dp2);

        return max(ans1,ans2);
    }
};