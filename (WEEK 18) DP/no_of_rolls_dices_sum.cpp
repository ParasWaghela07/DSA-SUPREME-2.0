//VARIENT 1
    class Solution {
public:
    int byRecursion(int n,int k,int target){
        if(n==0 && target==0){
            return 1;
        }
        if(n==0 && target!=0){
            return 0;
        }
        if(n!=0 && target==0){
            return 0;
        }

        int ans=0;
        for(int i=1;i<=k;i++){
            if(target-i>=0)
            ans=ans+byRecursion(n-1,k,target-i);
        }
        return ans;
    }
    int byMemo(int n,int k,int target,vector<vector<int>>&dp){
        if(n==0 && target==0){
            return 1;
        }
        if(n==0 && target!=0){
            return 0;
        }
        if(n!=0 && target==0){
            return 0;
        }
        if(dp[n][target]!=-1){
            return dp[n][target];
        }

        int ans=0;
        for(int i=1;i<=k;i++){
            if(target-i>=0)
            ans=(ans+byMemo(n-1,k,target-i,dp))%1000000007;
        }
        dp[n][target]=ans;
        return dp[n][target];
    }
    int byTabu(int n ,int k, int target){
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        for(int dice=0;dice<=n;dice++){
            for(int goal=0;goal<=target;goal++){
                
            }
        }
    }
    int numRollsToTarget(int n, int k, int target) {
        // int ans = byRecursion(n,k,target);
        
        // vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        // int ans=byMemo(n,k,target,dp);

        int ans=byTabu(n,k,target);
        return ans;
    }
};

//VARIENT 2
  int byRecursion2(int &n,int &k,int &target,int diceUsed,int currSum){
        if(diceUsed==n && currSum==target){
            return 1;
        }
        if(diceUsed==n && currSum!=target){
            return 0;
        }
        if(diceUsed!=n && currSum==target){
            return 0;
        }
        int ans=0;
        for(int i=1;i<=k;i++){
            ans=(ans+byRecursion2(n,k,target,diceUsed+1,currSum+i))%1000000007;
        }

        return ans;
    }
    int byMemo2(int &n,int &k,int &target,int diceUsed,int currSum,vector<vector<int>>&dp){
        if(diceUsed==n && currSum==target){
            return 1;
        }
        if(diceUsed==n && currSum!=target){
            return 0;
        }
        if(diceUsed!=n && currSum==target){
            return 0;
        }
        if(dp[diceUsed][currSum]!=-1){
            return dp[diceUsed][currSum];
        }
        int ans=0;
        for(int face=1;face<=k;face++){
            if(currSum+face<=target)
            ans=(ans+byMemo2(n,k,target,diceUsed+1,currSum+face,dp))%1000000007;
        }
        dp[diceUsed][currSum]=ans;
        return dp[diceUsed][currSum];
    }

    int byTabu2(int n,int k,int target){
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        dp[n][target]=1;

        for(int diceUsed=n-1;diceUsed>=0;diceUsed--){
            for(int currSum=target;currSum>=0;currSum--){
                int ans=0;
                for(int face=1;face<=k;face++){
                    if(currSum+face<=target)
                    ans=(ans+dp[diceUsed+1][currSum+face])%1000000007;
        }
        dp[diceUsed][currSum]=ans;
            }
        }

        return dp[0][0];
    }

    int byTabu2SO(int n,int k,int target){
        vector<int>curr(target+1,0);
        vector<int>next(target+1,0);

        next[target]=1;

        for(int diceUsed=n-1;diceUsed>=0;diceUsed--){
            for(int currSum=target;currSum>=0;currSum--){
                int ans=0;
                for(int face=1;face<=k;face++){
                    if(currSum+face<=target)
                    ans=(ans+next[currSum+face])%1000000007;
        }
        curr[currSum]=ans;
            }
            next=curr;
        }

        return next[0];
    }
    
    int numRollsToTarget(int n, int k, int target) {
        // int ans = byRecursion1(n,k,target);
        
        // vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        // int ans=byMemo1(n,k,target,dp);

        int diceUsed=0;
        int currSum=0;
        // int ans=byRecursion2(n,k,target,diceUsed,currSum);

        // vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        // // int ans=byMemo2(n,k,target,diceUsed,currSum,dp);

        // int ans=byTabu2(n,k,target);
        int ans=byTabu2SO(n,k,target);

        return ans;
    }
};