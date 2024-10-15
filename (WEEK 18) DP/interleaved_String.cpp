class Solution {
public:
    --------    3d dp -------------
    bool byRec(string&s1,string&s2,string&s3,int i,int j,int index){
        if(index>=s3.size() && i>=s1.size() && j>=s2.size()) return true;
        if(i>=s1.size() && j>=s2.size()) return false;

        bool op1=0;
        bool op2=0;

        if(i<s1.size() && s1[i]==s3[index]){
            op1=byRec(s1,s2,s3,i+1,j,index+1);
        }
        if(j<s2.size() && s2[j]==s3[index]){
            op2=byRec(s1,s2,s3,i,j+1,index+1);
        }

        return op1||op2;
    }

    bool byMem(string&s1,string&s2,string&s3,int i,int j,int index,vector<vector<vector<int>>>&dp){
        if(index>=s3.size() && i>=s1.size() && j>=s2.size()) return true;
        if(i>=s1.size() && j>=s2.size()) return false;

        if(dp[i][j][index]!=-1) return dp[i][j][index];

        bool op1=0;
        bool op2=0;

        if(i<s1.size() && s1[i]==s3[index]){
            op1=byMem(s1,s2,s3,i+1,j,index+1,dp);
        }
        if(j<s2.size() && s2[j]==s3[index]){
            op2=byMem(s1,s2,s3,i,j+1,index+1,dp);
        }

        return dp[i][j][index]=op1||op2;
    }

    bool byTabu(string&s1,string&s2,string&s3){
        vector<vector<vector<int>>>dp(s1.size()+1,(vector<vector<int>>(s2.size()+1,vector<int>(s3.size()+1,0))));
        dp[s1.size()][s2.size()][s3.size()]=1;

        for(int i=s1.size();i>=0;i--){
            for(int j=s2.size();j>=0;j--){
                for(int index=s3.size()-1;index>=0;index--){
                        bool op1=0;
                        bool op2=0;

                        if(i<s1.size() && s1[i]==s3[index]){
                            op1=dp[i+1][j][index+1];
                        }
                        if(j<s2.size() && s2[j]==s3[index]){
                            op2=dp[i][j+1][index+1];
                        }

                        dp[i][j][index]=op1||op2;
                }
            }
        }

        return dp[0][0][0];
    }

    bool bySO(string&s1,string&s2,string&s3){
        // vector<vector<vector<int>>>dp(s1.size()+1,(vector<vector<int>>(s2.size()+1,vector<int>(s3.size()+1,0))));
        // dp[s1.size()][s2.size()][s3.size()]=1;

        vector<int>curr(s2.size()+1,0);
        vector<int>next(s2.size()+1,0);
        vector<int>z(s2.size()+1,0);

        curr[s2.size()]=1;
        next[s2.size()]=1;
        z[s2.size()]=1;



        for(int i=s1.size();i>=0;i--){
            for(int j=s2.size();j>=0;j--){
                for(int index=s3.size()-1;index>=0;index--){
                        bool op1=0;
                        bool op2=0;

                        if(i<s1.size() && s1[i]==s3[index]){
                            op1=next[j]&&z[index+1];
                        }
                        if(j<s2.size() && s2[j]==s3[index]){
                            op2=curr[j+1]&&z[index+1];
                        }

                        curr[j]=op1||op2;
                }
            }
        }

        return dp[0][0][0];
    }


    bool isInterleave(string s1, string s2, string s3) {
        // return byRec(s1,s2,s3,0,0,0);

        // vector<vector<vector<int>>>dp(s1.size()+1,(vector<vector<int>>(s2.size()+1,vector<int>(s3.size()+1,-1))));
        // return byMem(s1,s2,s3,0,0,0,dp);

        return byTabu(s1,s2,s3);
    }
};