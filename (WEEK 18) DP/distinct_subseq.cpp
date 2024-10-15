class Solution {
public:
    int byRec(string &s,string &t,int i,int j){
        if(j>=t.size()){
            return 1;
        }

        if(i>=s.size()){
            return 0;
        }

        int include=0;
        if(s[i]==t[j]){
            include=byRec(s,t,i+1,j+1);
        }
        int exclude=byRec(s,t,i+1,j);

        return include+exclude;
    }

    int byMem(string &s,string &t,int i,int j,vector<vector<int>>&dp){
        if(j>=t.size()){
            return 1;
        }

        if(i>=s.size()){
            return 0;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        int include=0;
        if(s[i]==t[j]){
            include=byMem(s,t,i+1,j+1,dp);
        }
        int exclude=byMem(s,t,i+1,j,dp);

        return dp[i][j]=include+exclude;
    }

    int byTabu(string &s,string &t){
        vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,0));
        for(int i=0;i<=s.size();i++){
            dp[i][t.size()]=1;
        }

        for(int i=s.size()-1;i>=0;i--){
            for(int j=t.size()-1;j>=0;j--){
                long include=0;
                if(s[i]==t[j]){
                    include=dp[i+1][j+1];
                }
                long exclude=dp[i+1][j];

                if(include+exclude>=INT_MAX) dp[i][j]=0;
                else dp[i][j]=include+exclude;
            }
        }

        return dp[0][0];
    }

    int bySO(string &s,string &t){
        vector<int>next(t.size()+1,0);
        vector<int>curr(t.size()+1,0);

        for(int i=s.size()-1;i>=0;i--){
            next[t.size()]=1;
            for(int j=t.size()-1;j>=0;j--){
                long include=0;
                if(s[i]==t[j]){
                    include=next[j+1];
                }
                long exclude=next[j];

                if(include+exclude>=INT_MAX) curr[j]=0;
                else curr[j]=include+exclude;
            }

            next=curr;
        }

        return next[0];
    }
    int numDistinct(string s, string t) {
        // return byRec(s,t,0,0);

        // vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,-1));
        // return byMem(s,t,0,0,dp);

        // return byTabu(s,t);

        return bySO(s,t);
    }
};