class Solution {
public:
    int byRec(vector<int>&s,int index,int mul){
        if(index>=s.size()) return 0;

        int include=(s[index]*mul)+byRec(s,index+1,mul+1);
        int exclude=byRec(s,index+1,mul);

        return max(include,exclude);
    }

    int byMem(vector<int>&s,int index,int mul,vector<vector<int>>&dp){
        if(index>=s.size()) return 0;
        if(dp[index][mul]!=-1) return dp[index][mul];

        int include=(s[index]*mul)+byMem(s,index+1,mul+1,dp);
        int exclude=byMem(s,index+1,mul,dp);

        return dp[index][mul]=max(include,exclude);
    }

    int byTabu(vector<int>&s){
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+2,0));

        for(int index=s.size()-1;index>=0;index--){
            for(int mul=s.size();mul>=1;mul--){
                
                int include=(s[index]*mul)+dp[index+1][mul+1];
                int exclude=dp[index+1][mul];

                dp[index][mul]=max(include,exclude);
            }
        }

        return dp[0][1];
    }

    int bySO(vector<int>&s){
        vector<int>curr(s.size()+2,0);
        vector<int>next(s.size()+2,0);

        for(int index=s.size()-1;index>=0;index--){
            for(int mul=s.size();mul>=1;mul--){
                
                int include=(s[index]*mul)+next[mul+1];
                int exclude=next[mul];

                curr[mul]=max(include,exclude);
            }
            next=curr;
        }

        return next[1];
    }
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(),s.end());
        // return byRec(s,0,1);

        // vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
        // return byMem(s,0,1,dp);

        // return byTabu(s);

        return bySO(s);
    }
};