class Solution {
public:
int mod=1000000007;
    int byRecursion(int n,int &k,int target){
        if(n==0 && target==0){
            return 1;
        }

        if(n==0 && target > 0 ){
            return 0;
        }

        if(n<0) return 0;
        if(target<0) return 0;

        int ans=0;
        for(int i=1;i<=k;i++){
            ans += byRecursion(n-1,k,target-i) % mod;
        }

        return ans;
    }

    int bymemo(int n,int &k,int target,vector<vector<int>>&dp){
        if(n==0 && target==0){
            return 1;
        }

        if(n==0 && target > 0 ){
            return 0;
        }

        if(n<0) return 0;
        if(target<0) return 0;

        if(dp[n][target]!=-1) return dp[n][target]%mod;


        int ans=0;
        for(int i=1;i<=k;i++){
            ans=(ans + bymemo(n-1,k,target-i,dp) ) % mod;
        }

        return dp[n][target]=ans%mod;
    }
    int numRollsToTarget(int n, int k, int target) {

        // int ans=byRecursion(n,k,target);
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        int ans=bymemo(n,k,target,dp)%mod;
        return ans; 
    }
};











class Solution {
public:
    int byMemo(int &n,int &k,int diceUsed,int sum,int &target,vector<vector<int>>&dp){
        if(diceUsed==n && sum==target) return 1;
        if(diceUsed==n && sum!=target) return 0;
        if(diceUsed!=n && sum==target) return 0;
        if(dp[diceUsed][sum]!=-1) return dp[diceUsed][sum];
        int ans=0;
        for(int i=1;i<=k;i++){
            if(sum+i<=target)
            ans = (ans + byMemo(n,k,diceUsed+1,sum+i,target,dp))%1000000007;
        }

       return dp[diceUsed][sum]=ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        int diceUsed=0;
        int sum=0;
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        int ans=byMemo(n,k,diceUsed,sum,target,dp);

        return ans;
    }
};

