class Solution {
public:
    int byRecursion(string &a, string &b,int i, int j){
        if(i>=a.size() || j>=b.size()){
            return 0;
        }

        int ans=0;
        //mil gya match dono string me
        if(a[i]==b[j])
        ans = 1 + byRecursion(a,b,i+1,j+1);
        else
        ans = 0 +  max( byRecursion(a,b,i+1,j) , byRecursion(a,b,i,j+1) );

        return ans;
    }

    int byMemo(string &a , string &b, int i,int j,vector<vector<int>>&dp){
        if(i>=a.size() || j>=b.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans=0;
        if(a[i]==b[j]){
            ans=1 + byMemo(a,b,i+1,j+1,dp);
        }
        else{
            ans = 0 +  max( byMemo(a,b,i+1,j,dp) , byMemo(a,b,i,j+1,dp) );
        }

        dp[i][j]=ans;
        return dp[i][j];
    }

    int byTabu(string &a,string &b,int i,int j,vector<vector<int>> &dp){

        for(int i=a.size()-1;i>=0;i--){
            for(int j=b.size()-1;j>=0;j--){
                int ans=0;
                if(a[i]==b[j]){
                    ans=1 + dp[i+1][j+1];
                }
                else{
                    ans = 0 +  max(dp[i+1][j] , dp[i][j+1] );
                }
                dp[i][j]=ans;
            }
        }

        return dp[i][j];
    }

    int byTabuSO(string &a,string &b,int i,int j){
        vector<int>curr(a.size()+1,0);
        vector<int>next(a.size()+1,0);


for(int j=b.size()-1;j>=0;j--){
        for(int i=a.size()-1;i>=0;i--){
                   int ans=0;
                   if(a[i]==b[j]){
                       ans=1 + next[i+1];
                   }
                   else{
                       ans =0 + max(curr[i+1],next[i]);
                   }
                   curr[i]=ans;
               }   
               next = curr;
        }
        return next[0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int i=0;
        int j=0;
        
        int ans=byRecursion(text1,text2,i,j);
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,-1));
        int ans=byMemo(text1,text2,i,j,dp);

        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,0));
        int ans=byTabu(text1,text2,i,j,dp);

        int ans=byTabuSO(text1,text2,i,j);

        return ans;
    }
};


/////////////
class Solution {
public:
    int byRec(string& s1, string& s2, int i, int j) {
        if (i >= s1.size() || j >= s2.size()) {
            return 0;
        }

        int op1 = 0;
        if (s1[i] == s2[j]) {
            op1 = 1 + byRec(s1, s2, i + 1, j + 1);
        }
        int op2 = byRec(s1, s2, i + 1, j);
        int op3 = byRec(s1, s2, i, j + 1);

        return max(max(op1, op2), op3);
    }

    int byMem(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
        if (i >= s1.size() || j >= s2.size()) {
            return 0;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        int op1 = 0;
        if (s1[i] == s2[j]) {
            op1 = 1 + byMem(s1, s2, i + 1, j + 1, dp);
        }
        int op2 = byMem(s1, s2, i + 1, j, dp);
        int op3 = byMem(s1, s2, i, j + 1, dp);

        return dp[i][j] = max(max(op1, op2), op3);
    }

    int byTabu(string& s1, string& s2) {
        // by analyzing base case , we come to know that last row nd col is zero
        // , ie we did 0 instead of -1 in dp creation
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));

        for (int i = s1.size() - 1; i >= 0; i--) {
            for (int j = s2.size() - 1; j >= 0; j--) {
                int op1 = 0;
                if (s1[i] == s2[j]) {
                    op1 = 1 + dp[i + 1][j + 1];
                }
                int op2 = dp[i + 1][j];
                int op3 = dp[i][j + 1];

                dp[i][j]=max(op1,max(op2,op3));
            }
        }

        return dp[0][0];
    }

    // int byTabu(string &s1,string &s2){
    //     vector<vector<int>>dp(s1.size(),vector<int>(s2.size(),-1));
    // for(int j=0;j<s2.size();j++){
    //     for(int i=0;i<s1.size();i++){
    //             int dig=0;
    //             int left=0;
    //             int top=0;

    //             if(i-1>=0 && j-1>=0) dig=dp[i-1][j-1];
    //             if(i-1>=0) left=dp[i-1][j];
    //             if(j-1>=0) top=dp[i][j-1];

    //             if(s1[i]==s2[j]) dp[i][j]=dig+1;
    //             else dp[i][j]=max(left,top);
    //         }
    //     }

    //     return dp[s1.size()-1][s2.size()-1];
    // }

    int bySO(string&s1,string&s2){
        vector<int>curr(s1.size()+1,0);
        vector<int>next(s1.size()+1,0);


    for (int j = s2.size() - 1; j >= 0; j--) {
        for (int i = s1.size() - 1; i >= 0; i--) {
                int op1 = 0;
                if (s1[i] == s2[j]) {
                    op1 = 1 + next[i + 1];
                }
                int op2 = curr[i + 1];
                int op3 = next[i];

                curr[i]=max(op1,max(op2,op3));
            }
            next=curr;
        }

        return curr[0];
    }
    // int bySO(string& s1, string& s2) {
    //     vector<int> prev(s1.size() + 1, 0);
    //     vector<int> curr(s1.size() + 1, 0);

    //     for (int j = 0; j < s2.size(); j++) {
    //         for (int i = 0; i < s1.size(); i++) {
    //             if (s1[i] == s2[j])
    //                 curr[i + 1] = prev[i] + 1;
    //             else {
    //                 curr[i + 1] = max(curr[i], prev[i + 1]);
    //             }
    //         }

    //         prev = curr;
    //     }

    //     return curr[curr.size() - 1];
    // }

    int longestCommonSubsequence(string text1, string text2) {
        // int ans=byRec(text1,text2,0,0);

        // vector<vector<int>>dp(text1.size(),vector<int>(text2.size(),-1));
        // int ans=byMem(text1,text2,0,0,dp);

        // int ans = byTabu(text1, text2);

        int ans=bySO(text1,text2);

        return ans;
    }
};