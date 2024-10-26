class Solution {
public:
    int byRec(vector<string>&s,int m,int n,int index){
        if(index>=s.size()) return 0;

        int onesCount=0;
        int zeroesCount=0;

        for(auto it:s[index]){
            if(it=='1') onesCount++;
            else zeroesCount++;
        }

        int include=0;
        if(onesCount<=n && zeroesCount<=m){
            include=1+byRec(s,m-zeroesCount,n-onesCount,index+1);
        }

        int exclude=byRec(s,m,n,index+1);

        return max(include,exclude);
    }

    int byMem(vector<string>&s,int m,int n,int index,vector<vector<vector<int>>>&dp){
        if(index>=s.size()) return 0;
        if(dp[index][m][n]!=-1) return dp[index][m][n];

        int onesCount=0;
        int zeroesCount=0;

        for(auto it:s[index]){
            if(it=='1') onesCount++;
            else zeroesCount++;
        }

        int include=0;
        if(onesCount<=n && zeroesCount<=m){
            include=1+byMem(s,m-zeroesCount,n-onesCount,index+1,dp);
        }

        int exclude=byMem(s,m,n,index+1,dp);

        return dp[index][m][n]=max(include,exclude);
    }

    int byTabu(vector<string>& s, int m, int n){
        vector<vector<vector<int>>>dp(s.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));

        for(int index=s.size()-1;index>=0;index--){
            for(int m_i=0;m_i<=m;m_i++){
                for(int n_i=0;n_i<=n;n_i++){
                                    
                        int onesCount=0;
                        int zeroesCount=0;

                        for(auto it:s[index]){
                            if(it=='1') onesCount++;
                            else zeroesCount++;
                        }

                        int include=0;
                        if(onesCount<=n_i && zeroesCount<=m_i){
                            include=1+dp[index+1][m_i-zeroesCount][n_i-onesCount];
                        }

                        int exclude=dp[index+1][m_i][n_i];

                        dp[index][m_i][n_i]=max(include,exclude);
                }
            }
        }

        return dp[0][m][n];
    }

    int bySO(vector<string>& s, int m, int n){
        vector<vector<vector<int>>>dp(2,vector<vector<int>>(m+1,vector<int>(n+1,0)));

        for(int index=s.size()-1;index>=0;index--){
            for(int m_i=0;m_i<=m;m_i++){
                for(int n_i=0;n_i<=n;n_i++){
                                    
                        int onesCount=0;
                        int zeroesCount=0;

                        for(auto it:s[index]){
                            if(it=='1') onesCount++;
                            else zeroesCount++;
                        }

                        int include=0;
                        if(onesCount<=n_i && zeroesCount<=m_i){
                            include=1+dp[1][m_i-zeroesCount][n_i-onesCount];
                        }

                        int exclude=dp[1][m_i][n_i];

                        dp[0][m_i][n_i]=max(include,exclude);
                }
            }

            dp[1]=dp[0];
        }

        return dp[0][m][n];
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        // return byRec(strs,m,n,0);

        // vector<vector<vector<int>>>dp(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        // return byMem(strs,m,n,0,dp);

        // return byTabu(strs,m,n);

        return bySO(strs,m,n);
    }
};