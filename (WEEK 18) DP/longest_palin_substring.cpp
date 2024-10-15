class Solution {
public:
    bool byRec(string &s,int i,int j,int &maxLen,int &start){
        if(i>=j) return true;

        bool flag=false;
        if(s[i]==s[j]){
            flag=byRec(s,i+1,j-1,maxLen,start);
        }

        if(flag && j-i+1>maxLen){
            maxLen=j-i+1;
            start=i;
        }

        return flag;
    }

    bool byMem(string &s,int i,int j,int &maxLen,int &start,vector<vector<int>>&dp){
        if(i>=j) return true;

        if(dp[i][j]!=-1) return dp[i][j];

        bool flag=false;
        if(s[i]==s[j]){
            flag=byMem(s,i+1,j-1,maxLen,start,dp);
        }

        if(flag && j-i+1>maxLen){
            maxLen=j-i+1;
            start=i;
        }

        return dp[i][j]=flag;
    }
    
    string longestPalindrome(string s) {
        int maxLen=1;
        int start=0;

        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));


        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<s.size();j++){
                bool ans=byMem(s,i,j,maxLen,start,dp);
            }
        }

        return s.substr(start,maxLen);
    }
};