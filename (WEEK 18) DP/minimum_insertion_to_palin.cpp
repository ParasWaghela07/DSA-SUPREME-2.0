class Solution {
public:
    int byRec(string&s,int i,int j){
        if(i>=j) return 0;

        if(s[i]==s[j]){
            return byRec(s,i+1,j-1);
        }
        else{
            return 1+min(byRec(s,i+1,j),byRec(s,i,j-1));
        }
    }

    int byMem(string&s,int i,int j,vector<vector<int>>&dp){
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==s[j]){
            return dp[i][j]=byMem(s,i+1,j-1,dp);
        }
        else{
            return dp[i][j]=1+min(byMem(s,i+1,j,dp),byMem(s,i,j-1,dp));
        }
    }

    int byTabu(string&s){
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,0));

        for(int i=s.size()-1;i>=0;i--){
            for(int j=0;j<s.size();j++){

                    if(i>=j) continue;

                    if(s[i]==s[j]){
                        dp[i][j]=dp[i+1][j-1];
                    }
                    else{
                        dp[i][j]=1+min(dp[i+1][j],dp[i][j-1]);
                    }
            }
        }

        return dp[0][s.size()-1];
    }

    int bySO(string&s){
        vector<int>curr(s.size()+1,0);
        vector<int>next(s.size()+1,0);

        for(int i=s.size()-1;i>=0;i--){
            for(int j=0;j<s.size();j++){

                    if(i>=j) continue;

                    if(s[i]==s[j]){
                        curr[j]=next[j-1];
                    }
                    else{
                       curr[j]=1+min(next[j],curr[j-1]);
                    }
            }
            next=curr;
        }

        return next[s.size()-1];
    }

    int LCS(string&a,string&b,int i,int j){
        if(i>=a.size() || j>=b.size()) return 0;

        if(a[i]==b[j]) return 1 + LCS(a,b,i+1,j+1);
        else return max(LCS(a,b,i+1,j),LCS(a,b,i,j+1));
    }

    int LCS_TD(string&a,string&b,int i,int j,vector<vector<int>>&dp){
        if(i>=a.size() || j>=b.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        if(a[i]==b[j]) return dp[i][j]=1 + LCS_TD(a,b,i+1,j+1,dp);
        else return dp[i][j]=max(LCS_TD(a,b,i+1,j,dp),LCS_TD(a,b,i,j+1,dp));
    }

    int LCS_BU(string&a,string&b,vector<vector<int>>&dp){
       
        for(int i=a.size()-1;i>=0;i--){
            for(int j=b.size()-1;j>=0;j--){
                if(a[i]==b[j]) dp[i][j]=1 + dp[i+1][j+1];
                else dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            }
        }

        return dp[0][0];
    }

    int LCS_SO(string&a,string&b){
        vector<int>next(b.size()+1,0);
        vector<int>curr(b.size()+1,0);

        for(int i=a.size()-1;i>=0;i--){
            for(int j=b.size()-1;j>=0;j--){
                if(a[i]==b[j]) curr[j]=1 + next[j+1];
                else curr[j]=max(next[j],curr[j+1]);
            }
            next=curr;
        }

        return next[0];
    }
    int LPS(string &s){
        string a=s;
        reverse(s.begin(),s.end());
        string b=s;

        // return LCS(a,b,0,0);

        // vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
        // return LCS_TD(a,b,0,0,dp);

        // vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,0));
        // return LCS_BU(a,b,dp);

        return LCS_SO(a,b);
    }
    int minInsertions(string s) {
        // return byRec(s,0,s.size()-1);

        // vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
        // return byMem(s,0,s.size()-1,dp);

        // return bySO(s);

        return s.size()-LPS(s);
    }
};