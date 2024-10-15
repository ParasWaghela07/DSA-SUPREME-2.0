
-------- MAX PROFIT BY AT MOST 2 TRANSACTIONS ----------
-------  3D DP ----------

class Solution {
public:
    int byRec(vector<int>&p,int index,int buy,int limit){
        if(index>=p.size() || limit==0) return 0;
        int profit=0;

        if(buy){
            int op1=-p[index]+byRec(p,index+1,0,limit);
            int op2=byRec(p,index+1,1,limit);

            profit=max(op1,op2);
        }
        else{
            int op1=p[index]+byRec(p,index+1,1,limit-1);
            int op2=byRec(p,index+1,0,limit);

             profit=max(op1,op2);
        }

        return profit;
    }

    int byMem(vector<int>&p,int index,int buy,int limit,vector<vector<vector<int>>>&dp){
        if(index>=p.size() || limit==0) return 0;
        if(dp[index][buy][limit]!=-1) return dp[index][buy][limit];

        int profit=0;

        if(buy){
            int op1=-p[index]+byMem(p,index+1,0,limit,dp);
            int op2=byMem(p,index+1,1,limit,dp);

            profit=max(op1,op2);
        }
        else{
            int op1=p[index]+byMem(p,index+1,1,limit-1,dp);
            int op2=byMem(p,index+1,0,limit,dp);

             profit=max(op1,op2);
        }

        return dp[index][buy][limit]=profit;
    }

    int byTabu(vector<int>&p){
        vector<vector<vector<int>>>dp(p.size()+1,vector<vector<int>>(2,vector<int>(3,0)));

        for(int index=p.size()-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                for(int limit=1;limit<=2;limit++){
                        int profit=0;

                        if(buy){
                            int op1=-p[index]+dp[index+1][0][limit];
                            int op2=dp[index+1][1][limit];

                            profit=max(op1,op2);
                        }
                        else{
                            int op1=p[index]+dp[index+1][1][limit-1];
                            int op2=dp[index+1][0][limit];

                            profit=max(op1,op2);
                        }

                        dp[index][buy][limit]=profit;
                }
            }
        }
        return dp[0][1][2];
    }

    int bySO(vector<int>&p){
        vector<vector<vector<int>>>dp(2,vector<vector<int>>(2,vector<int>(3,0)));

        for(int index=p.size()-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                for(int limit=1;limit<=2;limit++){
                        int profit=0;

                        if(buy){
                            int op1=-p[index]+dp[1][0][limit];
                            int op2=dp[1][1][limit];

                            profit=max(op1,op2);
                        }
                        else{
                            int op1=p[index]+dp[1][1][limit-1];
                            int op2=dp[1][0][limit];

                            profit=max(op1,op2);
                        }

                        dp[0][buy][limit]=profit;
                }
            }
            dp[1]=dp[0];
        }
        return dp[0][1][2];
    }
    int maxProfit(vector<int>& prices) {
        // return byRec(prices,0,1,2);

        // vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,-1)));
        // return byMem(prices,0,1,2,dp);

        // return byTabu(prices);

        return bySO(prices);
    }
};

class Solution {
public:
    int byRec(vector<int>&p,int index,int buy){
        if(index>=p.size() || buy==0) return 0;

        int profit=0;
        if(!(buy&1)){
            int op1=-p[index]+byRec(p,index+1,buy-1);
            int op2=byRec(p,index+1,buy);

            profit=max(op1,op2);
        }
        else{
            int op1=p[index]+byRec(p,index+1,buy-1);
            int op2=byRec(p,index+1,buy);

            profit=max(op1,op2);
        }

        return profit;
    }

    int byMem(vector<int>&p,int index,int buy,vector<vector<int>>&dp){
        if(index>=p.size() || buy==0) return 0;
        if(dp[index][buy]!=-1) return dp[index][buy];

        int profit=0;
        if(!(buy&1)){
            int op1=-p[index]+byMem(p,index+1,buy-1,dp);
            int op2=byMem(p,index+1,buy,dp);

            profit=max(op1,op2);
        }
        else{
            int op1=p[index]+byMem(p,index+1,buy-1,dp);
            int op2=byMem(p,index+1,buy,dp);

            profit=max(op1,op2);
        }

        return dp[index][buy]=profit;
    }

    int byTabu(vector<int>&p){
        vector<vector<int>>dp(p.size()+1,vector<int>(5,0));

        for(int index=p.size()-1;index>=0;index--){
            for(int buy=1;buy<=4;buy++){
                    int profit=0;
                    if(!(buy&1)){
                        int op1=-p[index]+dp[index+1][buy-1];
                        int op2=dp[index+1][buy];

                        profit=max(op1,op2);
                    }
                    else{
                        int op1=p[index]+dp[index+1][buy-1];
                        int op2=dp[index+1][buy];

                        profit=max(op1,op2);
                    }

                    dp[index][buy]=profit;
            }
        }

        return dp[0][4];
    }

    int bySO(vector<int>&p){
        vector<int>next(5,0);
        vector<int>curr(5,0);

        for(int index=p.size()-1;index>=0;index--){
            for(int buy=1;buy<=4;buy++){
                    int profit=0;
                    if(!(buy&1)){
                        int op1=-p[index]+next[buy-1];
                        int op2=next[buy];

                        profit=max(op1,op2);
                    }
                    else{
                        int op1=p[index]+next[buy-1];
                        int op2=next[buy];

                        profit=max(op1,op2);
                    }

                    curr[buy]=profit;
            }

            next=curr;
        }
        return next[4];
    }
    int maxProfit(vector<int>& prices) {
        // return byRec(prices,0,4);

        // vector<vector<int>>dp(prices.size()+1,vector<int>(5,-1));
        // return byMem(prices,0,4,dp);

        // return byTabu(prices);

        return bySO(prices);
    }

};
