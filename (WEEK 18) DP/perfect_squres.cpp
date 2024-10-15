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
/////////////////
class Solution {
public:
    int byRec(int num,int &n){
        if(num==n){
            return 0;
        }

        int ans=INT_MAX;
        for(int i=sqrt(n);i>=1;i--){
            if(num+(i*i)<=n)
            ans=min(ans,1+byRec(num+(i*i),n));
        }

        return ans;
    }

    int byMem(int num,int &n,vector<int>&dp){
        if(num==n){
            return 0;
        }

        if(dp[num]!=-1) return dp[num];

        int ans=INT_MAX;
        for(int i=sqrt(n);i>=1;i--){
            if(num+(i*i)<=n)
            ans=min(ans,1+byMem(num+(i*i),n,dp));
        }

        return dp[num]=ans;
    }

    int byTabu(int &n){
        vector<int>dp(n+1,-1);
        dp[n]=0;

        for(int x=n-1;x>=0;x--){
            int ans=INT_MAX;
            for(int i=sqrt(n);i>=1;i--){
                if(x+(i*i)<=n)
                    ans=min(ans,1+dp[x+(i*i)]);
            }
            dp[x]=ans;
        }

        return dp[0];
    }
    int numSquares(int n) {
        // return byRec(0,n);

        // vector<int>dp(n+1,-1);
        // return byMem(0,n,dp);

        return byTabu(n);
    }

};