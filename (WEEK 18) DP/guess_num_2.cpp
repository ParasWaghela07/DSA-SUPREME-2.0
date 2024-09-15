class Solution {
public:
    int byRec(int s,int e){
        if(s>=e){
            return 0;
        }

        int ans=INT_MAX;
        for(int i=s;i<=e;i++){
            ans=min(ans,i+max(byRec(s,i-1),byRec(i+1,e)));
        }
        return ans;
    }

    int byMem(int s,int e,vector<vector<int>>&dp){
        if(s>=e){
            return 0;
        }
        if(dp[s][e]!=-1) return dp[s][e];

        int ans=INT_MAX;
        for(int i=s;i<=e;i++){
            ans=min(ans,i+max(byMem(s,i-1,dp),byMem(i+1,e,dp)));
        }
        return dp[s][e]=ans;
    }

    int byTabu(int n){
        vector<vector<int>>dp(n+2,vector<int>(n+1,0));

        for(int s=n-1;s>=1;s--){
            for(int e=1;e<=n;e++){
                if(s>=e) continue;

                int ans=INT_MAX;
                for(int i=s;i<=e;i++){
                    ans=min(ans,i+max(dp[s][i-1],dp[i+1][e]));
                }
                dp[s][e]=ans;
            }
        }

        return dp[1][n];
    }

//SO NOT POSSIBLE

    int getMoneyAmount(int n) {
        // return byRec(1,n);

        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // return byMem(1,n,dp);

        // return byTabu(n);

        return bySO(n);
    }
};