class Solution {
public:

    int byRecursion(int n){
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }

        int ans=INT_MAX;
        
        for(int i=1;i<=sqrt(n);i++){
            int perfectSqaure=i*i;
            int tempAns=1+byRecursion(n-perfectSqaure);
            ans=min(ans,tempAns);
        }

        return ans;
    }
    int byMemo(int n,vector<int>&dp){
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans=INT_MAX;
        
        for(int i=1;i<=sqrt(n);i++){
            int perfectSqaure=i*i;
            int tempAns=1+byMemo(n-perfectSqaure,dp);
            ans=min(ans,tempAns);
        }

        return dp[n]=ans;
    }
    int numSquares(int n) {
        // int ans=byRecursion(n);
        vector<int>dp(n+1,-1);
        int ans=byMemo(n,dp);
        return ans-1;
    }
};