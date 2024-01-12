    
    long long byRecursion(int n,int k){
        if(n==1){
            return k;
        }
        if(n==2){
            return k+k*(k-1);
        }
        
        return (k-1)*(byRecursion(n-1,k) + byRecursion(n-2,k));
    }
    
    
#define ll long long
ll byMemo(int n, int k, vector<ll>& dp) {
    
    if (n == 1) {
        return k;
    }
    if (n == 2) {
        return k + (k - 1) * k;
    }
    if (dp[n] != -1) {
        return dp[n];
    }

    dp[n] = (k - 1) * (byMemo(n - 1, k, dp) + byMemo(n - 2, k, dp));

    return dp[n];
    
}

ll byTabu(int n,int k,vector<ll> &dp){
    dp[1]=k;
    dp[2]=k+(k-1)*k;

    for(int i=3;i<=n;i++){
        dp[i]= (dp[i-1]+dp[i-2])*(k-1);
    }

    return dp[n];
}

ll byTabuSO(int n,int k){
    ll prev1=k;
    ll prev2=k+(k-1)*k;
    ll ans=0;
    
    for(int i=3;i<=n;i++){
        ans = (k-1)*(prev1 + prev2);
        prev1=prev2;
        prev2=ans;
    }
    return ans;
}

long long countWays(int n, int k) {
    vector<ll> dp(n + 1, -1);
    ll ans=byRecursion(n,k);
    ll ans = byMemo(n, k, dp);
    ll ans=byTabu(n,k,dp);
    ll ans=byTabuSO(n,k);
    return ans;
}
