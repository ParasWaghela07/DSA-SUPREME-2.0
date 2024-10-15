class Solution {
public:
    int byRec(vector<int>&piles,int index,int M,bool flag){
        if(index>=piles.size()){
            return 0;
        }

        int ans=flag ? INT_MIN : INT_MAX;
        int temp=0;
        for(int X=1;X<=2*M;X++){
            if(index+X-1 >= piles.size()) break;
            temp+=piles[index+X-1];
            if(flag){
                ans=max(ans,temp+byRec(piles,index+X,max(M,X),false));
            }
            else{
                ans=min(ans,byRec(piles,index+X,max(M,X),true));
            }
        }
        return ans;
    }

    int byMem(vector<int>&piles,int index,int M,bool flag,vector<vector<vector<int>>>&dp){
        if(index>=piles.size()){
            return 0;
        }

        if(dp[index][M][flag]!=-1)return dp[index][M][flag];

        int ans=flag ? INT_MIN : INT_MAX;
        int temp=0;
        for(int X=1;X<=2*M;X++){
            if(index+X-1 >= piles.size()) break;
            temp+=piles[index+X-1];
            if(flag){
                ans=max(ans,temp+byMem(piles,index+X,max(M,X),false,dp));
            }
            else{
                ans=min(ans,byMem(piles,index+X,max(M,X),true,dp));
            }
        }
        return dp[index][M][flag]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        // return byRec(piles,0,1,true);

        vector<vector<vector<int>>>dp(piles.size()+1,vector<vector<int>>(piles.size()+1,vector<int>(2,-1)));
        return byMem(piles,0,1,true,dp);
    }
};