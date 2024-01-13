class Solution {
public:
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
    
    int byMemo(string &a, string &b,int i,int j,vector<vector<int>> &dp){
        if(i>=a.size() || j>=b.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans=0;
        if(a[i]==b[j]){
            ans = 1 + byMemo(a,b,i+1,j+1,dp);
        }
        else{
            ans = 0 + max( byMemo(a,b,i+1,j,dp),byMemo(a,b,i,j+1,dp));
        }

        dp[i][j]=ans;
        return ans;
    }
    int longestPalindromeSubseq(string s) {
        string s2=s;
        reverse(s2.begin(),s2.end());

        int i=0;
        int j=0;
        vector<vector<int>>dp(s.size()+1 , vector<int>(s2.size()+1, -1 ));
        int ans = byMemo(s,s2,i,j,dp);

        return ans;
    }
};