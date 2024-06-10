class Solution { ////////////// DYNAMIC PROGRAMMING QST , NOT SUBMITTED IN LEETCODE
public:
    int solve(vector<int>&coins,int amount){
        if(amount==0){
            return 0;
        }

        int mini=INT_MAX;
        int ans=INT_MAX;

        for(int i=0;i<coins.size();i++){
            int coin=coins[i];

            //current coin used when value of coin <=amount
            if(coin<=amount){
               int RecAns=solve(coins,amount-coin);

               if(RecAns!=INT_MAX)
               ans=1+RecAns;
            }
            mini=min(mini,ans);
        }

        return mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans=solve(coins,amount);

        if(ans==INT_MAX) return -1;

        return ans;
    }
};


class Solution {
public:
    int byRecursion(vector<int>&coins,int amt){
        if(amt==0) return 0;

        if(amt<0) return 1e9;
        int ans=1e9;
        for(int i=0;i<coins.size();i++){
            int op=1+byRecursion(coins,amt-coins[i]);
            ans=min(ans,op);
        }

        return ans;
    }
    int byMemo(vector<int>&coins,int amt,vector<int>&dp){
        if(amt==0) return 0;

        if(amt<0) return 1e9;

        if(dp[amt]!=-1) return dp[amt];
        int ans=1e9;
        for(int i=0;i<coins.size();i++){
            int op=1+byMemo(coins,amt-coins[i],dp);
            ans=min(ans,op);
        }

        return dp[amt]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        // int ans=byRecursion(coins,amount);

        vector<int>dp(amount+1,-1);
        int ans=byMemo(coins,amount,dp);
        if(ans>=1e9) return -1;
        return ans;
    }
};