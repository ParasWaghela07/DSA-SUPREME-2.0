class Solution {
public:
   --LEETCODE 689--
   int helper(int count ,vector<int>&prefixSum,int i,int k,vector<vector<int>>&dp){
         if(count==0) return 0 ;
        if(i>=prefixSum.size()) return INT_MIN;
        if(dp[count][i]!=-1) return dp[count][i];
        int take=prefixSum[i]+helper(count-1,prefixSum,i+k,k,dp);
        int not_take = helper(count,prefixSum,i+1,k,dp);
        return  dp[count][i]= max(take,not_take);
   }
    void solve (int k,int i,vector<int>&nums,vector<int>&prefixSum,int count,vector<int>&ans,vector<vector<int>>&dp){
        if (count == 0) return;
        if (i >= nums.size()) return; 
        int take=prefixSum[i]+helper(count-1,prefixSum,i+k,k,dp);
        int not_take = helper(count,prefixSum,i+1,k,dp);
        if(take >=not_take){
            ans.push_back(i);
            solve(k,i+k,nums,prefixSum,count-1,ans,dp);
        } 
        else solve(k,i+1,nums,prefixSum,count,ans,dp);
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int>prefixSum;
        int i = 0 ,j=0;
        int windowSum =0;
        while(j<nums.size()){
            windowSum+=nums[j];
            if(j-i+1==k){
                prefixSum.push_back(windowSum);
                windowSum-=nums[i];
                i++;
            }
            j++;
        }
       // for(auto it:prefixSum) cout<<it<<" ";

        vector<int>ans;
        vector<vector<int>> dp(4, vector<int>(prefixSum.size(), -1));
        int count =3;
        solve(k,0,nums,prefixSum,count,ans,dp);
        return ans;
    }
};