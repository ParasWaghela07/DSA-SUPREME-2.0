int byMemoisation(vector<int>&dp,int n){
        if(n<0){
            return 0;
        }
        if(n==0){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }

        dp[n]=byMemoisation(dp,n-1) + byMemoisation(dp,n-2);
        return dp[n];
    }
    int climbStairs(int n) {
        // return byRecursion(n);
        vector<int>dp(n+1,-1);
        return byMemoisation(dp,n);
    }

//////////////////////////////////////////////////

 int climbStairs(int n) {
        // return byRecursion(n);
        vector<int>dp(n+1,-1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1] + dp[i-2];
        }

        return dp[n];
        // return byMemoisation(dp,n);
    }