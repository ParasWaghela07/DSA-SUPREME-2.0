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

//////////////
class Solution {
public:
    int byRec(string &w1,string &w2,int i,int j){
        if(i>=w1.size()){
            return w2.size()-j;
        }
        if(j>=w2.size()){
            return w1.size()-i;
        }

        int ans=0;
        if(w1[i]==w2[j]){
            ans=byRec(w1,w2,i+1,j+1);
        }
        else{
            int op1=1+byRec(w1,w2,i,j+1);
            int op2=1+byRec(w1,w2,i+1,j);
            int op3=1+byRec(w1,w2,i+1,j+1);

            ans=min(min(op1,op2),op3);
        }

        return ans;
    }

    int byMem(string &w1,string &w2,int i,int j,vector<vector<int>>&dp){
        if(i>=w1.size()){
            return w2.size()-j;
        }
        if(j>=w2.size()){
            return w1.size()-i;
        }

        if(dp[i][j]!=-1)return dp[i][j];

        int ans=0;
        if(w1[i]==w2[j]){
            ans=byMem(w1,w2,i+1,j+1,dp);
        }
        else{
            int op1=1+byMem(w1,w2,i,j+1,dp);
            int op2=1+byMem(w1,w2,i+1,j,dp);
            int op3=1+byMem(w1,w2,i+1,j+1,dp);

            ans=min(min(op1,op2),op3);
        }

        return dp[i][j]=ans;
    }
    int byTabu(string &w1,string &w2){
        vector<vector<int>>dp(w1.size()+1,vector<int>(w2.size()+1,1e9));

        for(int j=0;j<=w2.size();j++){
            dp[w1.size()][j]=w2.size()-j;
        }

        for(int i=0;i<=w1.size();i++){
            dp[i][w2.size()]=w1.size()-i;
        }

        for(int i=w1.size()-1;i>=0;i--){
            for(int j=w2.size()-1;j>=0;j--){
                int ans=0;
                if(w1[i]==w2[j]){
                    ans=dp[i+1][j+1];
                }
                else{
                    int op1=1+dp[i][j+1];
                    int op2=1+dp[i+1][j];
                    int op3=1+dp[i+1][j+1];

                    ans=min(min(op1,op2),op3);
                }
                dp[i][j]=ans;
            }
        }

        return dp[0][0];
    }

    int bySO(string &w1,string &w2){
        vector<int>curr(w1.size()+1,0);
        vector<int>next(w1.size()+1,0);

        for(int i=0;i<=w1.size();i++){
            next[i]=w1.size()-i;
        }


    for(int j=w2.size()-1;j>=0;j--){
        curr[w1.size()]=w2.size()-j;
        for(int i=w1.size()-1;i>=0;i--){
                int ans=0;
                if(w1[i]==w2[j]){
                    ans=next[i+1];
                }
                else{
                    int op1=1+next[i];
                    int op2=1+curr[i+1];
                    int op3=1+next[i+1];

                    ans=min(min(op1,op2),op3);
                }
                curr[i]=ans;
            }
            next=curr;
        }

        return next[0];
    }
    int minDistance(string word1, string word2) {
        // int ans=byRec(word1,word2,0,0);

        // vector<vector<int>>dp(word1.size(),vector<int>(word2.size(),-1));
        // int ans=byMem(word1,word2,0,0,dp);

        // int ans=byTabu(word1,word2);

        int ans=bySO(word1,word2);

        return ans;
    }
};