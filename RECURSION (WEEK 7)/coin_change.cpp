class Solution { ////////////// DYNAMIC PROGRAMMING QST , NOT SUBMITTED IN LEETCODE
public:
    int solve(vector<int>&coins,int amount){
        if(amount==0){
            return 0;
        }

        int mini=INT_MAX;
        int ans=INT_MAX;

        for(int i=0;i<coins.size();i++){
            int coin=coins[i];

            //current coin used when value of coin <=amount
            if(coin<=amount){
               int RecAns=solve(coins,amount-coin);

               if(RecAns!=INT_MAX)
               ans=1+RecAns;
            }
            mini=min(mini,ans);
        }

        return mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans=solve(coins,amount);

        if(ans==INT_MAX) return -1;

        return ans;
    }
};