class Solution {
public:
    int byRecursion(vector<int>&coins , int amount ){
        if(amount==0){
            return 0;
        }

        int mini=INT_MAX;
        int ans=INT_MAX;

        for(int i=0;i<coins.size();i++){
            if(coins[i] <= amount ){
            int temp=byRecursion(coins,amount-coins[i]);
            if(temp!=INT_MAX){
                ans=1 + temp;
            }
            }
            mini=min(ans,mini);
        }

        return mini;
    }

    int byMemoisation (vector<int>&coins,int amount,vector<int>&dp){
        if(amount==0){
            return 0;
        }
        if(dp[amount]!=-1){
            return dp[amount];
        }
        int ans=INT_MAX;
        int mini=INT_MAX;

        for(int i=0;i<coins.size();i++){
            if(coins[i]<=amount){
                int temp=byMemoisation(coins,amount-coins[i],dp);

                if(temp!=INT_MAX){
                    ans=1 + temp;
                }
            }
            mini=min(ans,mini);
        }

        dp[amount]=mini;

        return dp[amount];

    }

    int byTabulation(vector<int>&coins,int amount,vector<int>&dp){
        dp[0]=0;
        for(int value=1;value<=amount;value++){
           int mini=INT_MAX;
           int ans=INT_MAX;
           for(int i=0;i<coins.size();i++){
               if(coins[i] <= value){
                   int temp = dp[value - coins[i] ];
                   if(temp!=INT_MAX){
                        ans= 1 + temp;
                   }
               }
               mini=min(mini,ans);
           }
           dp[value]=mini;
        }

        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        // int ans=byRecursion(coins,amount);
        

        // vector<int>dp(amount + 1 ,-1);
        // int ans = byMemoisation(coins,amount,dp);

        vector<int>dp(amount+1,INT_MAX);
        int ans= byTabulation(coins,amount,dp);
        if(ans!=INT_MAX)
        return ans;
        else
        return -1;
        
    }
};