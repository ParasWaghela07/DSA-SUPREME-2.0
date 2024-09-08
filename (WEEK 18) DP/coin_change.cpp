class Solution {
public:
    int byRec(vector<int>&coins,int index,int amount){
        if(amount==0){
            return 0;
        }
        if(amount<0) return 1e9;

        int ans=1e9;
        for(int i=index;i<coins.size();i++){
            int op=1+byRec(coins,index,amount-coins[i]);
            ans=min(ans,op);
        }

        return ans;
    }
    int byMem(vector<int>&coins,int index,int amount,vector<vector<int>>&dp){
        if(amount==0){
            return 0;
        }
        if(amount<0) return 1e9;
        if(dp[index][amount]!=-1) return dp[index][amount];

        int ans=1e9;
        for(int i=index;i<coins.size();i++){
            int op=1+byMem(coins,index,amount-coins[i],dp);
            ans=min(ans,op);
        }

        return dp[index][amount]=ans;
    }
    int byTabu(vector<int>&coins,int amount){
        vector<int>dp(amount+1,1e9);
        dp[0]=0;
        for(int value=1;value<=amount;value++){
           int mini=1e9;
           int ans=1e9;
           for(int i=0;i<coins.size();i++){
               if(coins[i] <= value){
                   int temp = dp[value - coins[i] ];
                   if(temp!=1e9){
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
        // int ans=byRec(coins,0,amount);

        // vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        // int ans=byMem(coins,0,amount,dp);

        int ans=byTabu(coins,amount);
        return ans==1e9?-1:ans;
    }
};



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


