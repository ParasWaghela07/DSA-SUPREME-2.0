//RECURSIVE METHOD
class Solution {
public:
    int fiboByRecursion(int n){
        if(n==0 || n==1){
            return n;
        }

        return fiboByRecursion(n-1) + fiboByRecursion(n-2);
    }
    int fib(int n) {
        int ans=fiboByRecursion(n);

        return ans;
    }
};

///MEMOISATION APPROACH // TOP-DOWN APPROACH + RECURSION
class Solution {
public:
    int fiboByRecursion(int n){
        if(n==0 || n==1){
            return n;
        }

        return fiboByRecursion(n-1) + fiboByRecursion(n-2);
    }
    int fiboByMemoisation(int n,vector<int>&dp){
        if(n==0 || n==1){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }

        dp[n]=fiboByMemoisation(n-1,dp) + fiboByMemoisation(n-2,dp);

        return dp[n];
    }
    int fib(int n) {
        // int ans=fiboByRecursion(n);
        vector<int>dp(n+1,-1);
        int ans=fiboByMemoisation(n,dp);
        return ans;
    }
};

//TABULAR APPROACH // ITERATIVE //BOTTOM-UP

vector<int>dp(n+1,-1);
        dp[0]=0;
        if(dp.size()==1){
            return dp[0];
        }       
        dp[1]=1;

        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1] + dp[i-2];
        }

        return dp[n];

//SPACE REDUCTION // SPACE SEARCH METHOD // NOT ALWAYS POSSIBLE
int i=0;
        if(n==0 || n==1){
            return n;
        }
        int j=1;
        int k=0;
        for(int index=2;index<=n;index++){
            k=i+j;
            i=j;
            j=k;
        }

        return k;