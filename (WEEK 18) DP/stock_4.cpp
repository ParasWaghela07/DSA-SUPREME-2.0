


-------- MAX PROFIT BY AT MOST K TRANSACTIONS ----------

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

    int byTabu(vector<int>&p,int &k){
        vector<vector<vector<int>>>dp(p.size()+1,vector<vector<int>>(2,vector<int>(k+1,0)));

        for(int index=p.size()-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                for(int limit=1;limit<=k;limit++){
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
        return dp[0][1][k];
    }

    int bySO(vector<int>&p,int &k){
        vector<vector<vector<int>>>dp(2,vector<vector<int>>(2,vector<int>(k+1,0)));

        for(int index=p.size()-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                for(int limit=1;limit<=k;limit++){
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
        return dp[0][1][k];
    }
    int maxProfit(int k, vector<int>& prices) {
        // return byRec(prices,0,1,k);

        // vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        // return byMem(prices,0,1,k,dp);

        // return byTabu(prices,k);

        return bySO(prices,k);
    }
};