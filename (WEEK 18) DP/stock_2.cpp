
------  MAX PROFIT BY INFINITE TRANSACTIONS ----

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]-prices[i-1]>0) sum+=prices[i]-prices[i-1];
        }

        return sum;
    }
};

////////

class Solution {
public:
    int byRec(vector<int>&p,int index,int buy){
        if(index>=p.size()) return 0;
        int profit=0;

        if(buy){
            int op1=-p[index]+byRec(p,index+1,0);
            int op2=byRec(p,index+1,1);

            profit=max(op1,op2);
        }
        else{
            int op1=p[index]+byRec(p,index+1,1);
            int op2=byRec(p,index+1,0);

            profit=max(op1,op2);
        }

        return profit;
    }

    int byMem(vector<int>&p,int index,int buy,vector<vector<int>>&dp){
        if(index>=p.size()) return 0;
        int profit=0;

        if(dp[index][buy]!=-1) return dp[index][buy];

        if(buy){
            int op1=-p[index]+byMem(p,index+1,0,dp);
            int op2=byMem(p,index+1,1,dp);

            profit=max(op1,op2);
        }
        else{
            int op1=p[index]+byMem(p,index+1,1,dp);
            int op2=byMem(p,index+1,0,dp);

            profit=max(op1,op2);
        }

        return dp[index][buy]=profit;
    }

    int byTabu(vector<int>&p){
        vector<vector<int>>dp(p.size()+1,vector<int>(2,0));

        for(int index=p.size()-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                    int profit=0;

                    if(buy){
                        int op1=-p[index]+dp[index+1][0];
                        int op2=dp[index+1][1];

                        profit=max(op1,op2);
                    }
                    else{
                        int op1=p[index]+dp[index+1][1];
                        int op2=dp[index+1][0];

                        profit=max(op1,op2);
                    }

                    dp[index][buy]=profit;
            }
        }

        return dp[0][1];
    }

    int bySO(vector<int>&p){
        vector<int>curr(2,0);
        vector<int>next(2,0);

        for(int index=p.size()-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                    int profit=0;

                    if(buy){
                        int op1=-p[index]+next[0];
                        int op2=next[1];

                        profit=max(op1,op2);
                    }
                    else{
                        int op1=p[index]+next[1];
                        int op2=next[0];

                        profit=max(op1,op2);
                    }

                    curr[buy]=profit;
            }
            next=curr;
        }

        return next[1];
    }
    int maxProfit(vector<int>& prices) {
        // return byRec(prices,0,1);

        // vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        // return byMem(prices,0,1,dp);

        // return byTabu(prices);

        return bySO(prices);
    }
};