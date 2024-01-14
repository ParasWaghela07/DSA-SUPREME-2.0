class Solution {
public:
    int byRecursion(string &a,string &b,int i,int j){
        if(i>=a.size()){
            return b.size()-j;
        }
        if(j>=b.size()){
            return a.size()-i;
        }

        int ans=INT_MAX;
        if(a[i]==b[j]){
            ans = 0 + byRecursion(a,b,i+1,j+1);
        }
        else{
            int replace = 1 + byRecursion(a,b,i+1,j+1);
            int insert= 1 + byRecursion(a,b,i,j+1);
            int deletion= 1 + byRecursion(a,b,i+1,j);
            ans = min (min(replace , insert ) , deletion);
        }

        return ans;
    }
    int byMemo(string &a,string &b,int i,int j,vector<vector<int>> &dp){
        if(i>=a.size()){
            return b.size()-j;
        }
        if(j>=b.size()){
            return a.size()-i;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans=INT_MAX;
        if(a[i]==b[j]){
            ans = 0 + byMemo(a,b,i+1,j+1,dp);
        }
        else{
            int replace = 1 + byMemo(a,b,i+1,j+1,dp);
            int insert= 1 + byMemo(a,b,i,j+1,dp);
            int deletion= 1 + byMemo(a,b,i+1,j,dp);
            ans = min (min(replace , insert ) , deletion);
        }

        dp[i][j]=ans;
        return dp[i][j];

    }

    int byTabu(string &a, string &b, vector<vector<int>> &dp){
        for(int col=0;col<=b.size();col++){
            dp[a.size()][col]= b.size()-col;
        }

        for(int row=0;row<=a.size();row++){
            dp[row][b.size()]=a.size()-row;
        }

        for(int i=a.size()-1;i>=0;i--){
            for(int j=b.size()-1;j>=0;j--){
                    int ans=INT_MAX;
                    if(a[i]==b[j]){
                        ans= 0 + dp[i+1][j+1];
                    }
                    else{
                        int replace = 1 + dp[i+1][j+1];
                        int insert= 1 + dp[i][j+1];
                        int deletion= 1 + dp[i+1][j];
                        ans = min (min(replace , insert ) , deletion);
                    }

                    dp[i][j]=ans;
        }
    }

    return dp[0][0];

    }

    int byTabuSO(string &a, string &b){
        
        vector<int>curr(a.size()+1,-1);
        vector<int>next(a.size()+1,-1);

        for(int row=0;row<=a.size();row++){
            next[row]=a.size()-row;
        }

        for(int col = b.size()-1; col >=0 ; col--){

            curr[a.size()]=b.size()-col;

            for(int row=a.size()-1;row>=0;row--){

                int ans=INT_MAX;

                if(a[row]==b[col]){
                    ans = 0 + next[row+1];
                }
                else{
                    int replace= 1 + next[row+1];
                    int insert = 1 + next[row];
                    int deletion= 1 + curr[row+1];
                    ans = min (min(replace , insert ) , deletion);
                }
                curr[row]=ans;
            }

            next=curr;
        }
        return next[0];
    }
    int minDistance(string word1, string word2) {
        int i=0;
        int j=0;
        // int ans=byRecursion(word1,word2,i,j);

        vector<vector<int>>dp(word1.size() + 1 , vector<int>(word2.size()+1 , -1));
        // int ans=byMemo(word1,word2,i,j,dp);

        // int ans=byTabu(word1,word2,dp);

        int ans=byTabuSO(word1,word2);

        return ans;
    }
};