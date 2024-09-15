
//VARIENT 1
class Solution {
public:
    int mod = 1000000007;
    int byRec(int dices, int& faces, int target) {
        if (target < 0)
            return 0;
        if (dices == 0 && target > 0)
            return 0;
        if (dices == 0 && target == 0)
            return 1;

        int ans = 0;
        for (int i = 1; i <= faces; i++) {
            ans = (ans + byRec(dices - 1, faces, target - i)) % mod;
        }
        return ans;
    }

    int byMem(int dices, int& faces, int target, vector<vector<int>>& dp) {
        if (target < 0)
            return 0;
        if (dices == 0 && target > 0)
            return 0;
        if (dices == 0 && target == 0)
            return 1;
        if (dp[dices][target] != -1)
            return dp[dices][target];

        int ans = 0;
        for (int i = 1; i <= faces; i++) {
            ans = (ans + byMem(dices - 1, faces, target - i, dp)) % mod;
        }
        return dp[dices][target] = ans;
    }

    int byTabu(int& n, int& k, int& target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        dp[0][0] = 1;

        for (int dices = 1; dices <= n; dices++) {
            for (int tar = 0; tar <= target; tar++) {
                int ans = 0;
                for (int i = 1; i <= k; i++) {
                    if (tar - i >= 0)
                        ans = (ans + dp[dices - 1][tar - i]) % mod;
                }
                dp[dices][tar] = ans;
            }
        }

        return dp[n][target];
    }

    int bySO(int &n,int &k,int &target){
        vector<int>prev(target+1,0);
        vector<int>curr(target+1,0);
        
        prev[0]=1;

        for (int dices = 1; dices <= n; dices++) {
            
            for (int tar = 0; tar <= target; tar++) {
                int ans = 0;
                for (int i = 1; i <= k; i++) {
                    if (tar - i >= 0)
                        ans = (ans + prev[tar - i]) % mod;
                }
                curr[tar] = ans;
            }
            prev=curr;
        }

        return prev[target];

    }

    int numRollsToTarget(int n, int k, int target) {
        // return byRec(n,k,target);

        // vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        // return byMem(n,k,target,dp);

        // return byTabu(n, k, target);

        return bySO(n,k,target);
    }
};

//VARIENT 2
class Solution {
public:
  
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
            for(int currSum=target-1;currSum>=0;currSum--){
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
            for(int currSum=target-1;currSum>=0;currSum--){
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

// OWN VARIENT
class Solution {
public:
    int mod=1000000007;
    int byRec(int dices,int &faces,int &target,int sum){
        if(sum>target) return 0;
        if(dices==0 && sum<target) return 0;
        if(dices==0 && sum==target) return 1;

        int ans=0;
        for(int i=1;i<=faces;i++){
            ans=(ans+byRec(dices-1,faces,target,sum+i))%mod;
        }

        return ans;
    }

    int byMem(int dices,int &faces,int &target,int sum, vector<vector<int>>&dp){
        if(sum>target) return 0;
        if(dices==0 && sum<target) return 0;
        if(dices==0 && sum==target) return 1;

        if(dp[dices][sum]!=-1) return dp[dices][sum];

        int ans=0;
        for(int i=1;i<=faces;i++){
            ans=(ans+byMem(dices-1,faces,target,sum+i,dp))%mod;
        }
        return dp[dices][sum]=ans;
    }

    int byTabu(int n,int &faces,int &target){
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));

        dp[0][target]=1;

        for(int dices=0;dices<=n;dices++){
            for(int sum=target-1;sum>=0;sum--){
                if(dices==0) continue;
                int ans=0;
                for(int i=1;i<=faces;i++){
                    if(sum+i <= target)
                    ans=(ans+dp[dices-1][sum+i])%mod;
                }
                dp[dices][sum]=ans;
            }
        }

        return dp[n][0];
    }

int bySO(int n, int &faces, int &target) {
    vector<int> prev(target + 1, 0);


    prev[target] = 1;

    for (int dices = 1; dices <= n; dices++) {
        vector<int> curr(target + 1, 0); 
        
        for (int sum = target - 1; sum >= 0; sum--) {
            int ans = 0;
            for (int i = 1; i <= faces; i++) {
                if (sum + i <= target)
                    ans = (ans + prev[sum + i]) % mod;
            }
            curr[sum] = ans;
        }
        
        prev = curr;  // Update prev with the values of curr
    }

    return prev[0];
}

    int numRollsToTarget(int n, int k, int target) {
        // return byRec(n,k,target,0);

        // vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        // return byMem(n,k,target,0,dp);

        // return byTabu(n,k,target);

        return bySO(n,k,target);
    }
};