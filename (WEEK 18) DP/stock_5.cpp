


-------- MAX PROFIT BY INFINITE TRANSACTIONS WITH FEE ----------

class Solution {
public:
    int byRec(vector<int>&p,int index,int buy,int &fee){
        if(index>=p.size()) return 0;
        int profit=0;

        if(buy){
            int op1=-p[index]+byRec(p,index+1,0,fee);
            int op2=byRec(p,index+1,1,fee);

            profit=max(op1,op2);
        }
        else{
            int op1=p[index]+byRec(p,index+1,1,fee)-fee;
            int op2=byRec(p,index+1,0,fee);

            profit=max(op1,op2);
        }

        return profit;
    }

    int byMem(vector<int>&p,int index,int buy,vector<vector<int>>&dp,int &fee){
        if(index>=p.size()) return 0;
        int profit=0;

        if(dp[index][buy]!=-1) return dp[index][buy];

        if(buy){
            int op1=-p[index]+byMem(p,index+1,0,dp,fee);
            int op2=byMem(p,index+1,1,dp,fee);

            profit=max(op1,op2);
        }
        else{
            int op1=p[index]+byMem(p,index+1,1,dp,fee)-fee;
            int op2=byMem(p,index+1,0,dp,fee);

            profit=max(op1,op2);
        }

        return dp[index][buy]=profit;
    }

    int byTabu(vector<int>&p,int &fee){
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
                        int op1=p[index]+dp[index+1][1]-fee;
                        int op2=dp[index+1][0];

                        profit=max(op1,op2);
                    }

                    dp[index][buy]=profit;
            }
        }

        return dp[0][1];
    }

    int bySO(vector<int>&p,int &fee){
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
                        int op1=p[index]+next[1]-fee;
                        int op2=next[0];

                        profit=max(op1,op2);
                    }

                    curr[buy]=profit;
            }
            next=curr;
        }

        return next[1];
    }
    int maxProfit(vector<int>& prices,int fee) {
        // return byRec(prices,0,1,fee);

        // vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        // return byMem(prices,0,1,dp,fee);

        // return byTabu(prices,fee);

        return bySO(prices,fee);
    }
};