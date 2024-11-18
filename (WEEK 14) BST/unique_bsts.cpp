class Solution
{
    public:
    //Function to return the total number of possible unique BST.
    int mod=1000000007;

    USED '1LL'  TO MAKE MULTIPLICATION HAPPEN IN LONG LONG
    
    int byMem(int n,vector<int>&dp){
        if(n<=1) return 1;
        if(dp[n]!=-1)return dp[n];
        
        int count=0;
        for(int i=1;i<=n;i++){
            int NodesLeftBehind=byMem(i-1,dp);
            int NodesLeftAfter=byMem(n-i,dp);
            
            count=(count+(1LL*NodesLeftBehind*NodesLeftAfter)%mod)%mod;
        }
        return dp[n]=count;
    }
    
        int byTabu(int n) {
        vector<int> dp(n + 1, 1);

        for (int nodes = 1; nodes <= n; nodes++) {
            int ans = 0;
            for (int i = 1; i <= nodes; i++) {
                ans =(ans+(1LL*dp[i - 1] * dp[nodes - i])%mod)%mod;
            }
            dp[nodes] = ans;
        }

        return dp[n];
    }
    
    int byRec(int n){
        if(n<=1) return 1;
        
        int count=0;
        for(int i=1;i<=n;i++){
            count+=byRec(i-1)*byRec(n-i);
        }
        return count;
    }
    
    int numTrees(int N) 
    {
        // return byRec(N);
        // vector<int>dp(N+1,-1);
        return byTabu(N);
    }
};