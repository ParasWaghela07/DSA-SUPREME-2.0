class Solution {
public:
    int byRec(string &s1,string &s2,int i,int j){
        if(i>=s1.size() && j>=s2.size()){
            return 0;
        }

        if(i>=s1.size()){
            int ttl=0;
            while(j<s2.size()){
                ttl+=s2[j];
                j++;
            }

            return ttl;
        }

        if(j>=s2.size()){
            int ttl=0;
            while(i<s1.size()){
                ttl+=s1[i];
                i++;
            }

            return ttl;
        }

        if(s1[i]==s2[j]){
            return byRec(s1,s2,i+1,j+1);
        }
        else{
            int op1=s1[i]+byRec(s1,s2,i+1,j);
            int op2=s2[j]+byRec(s1,s2,i,j+1);
            int op3=s1[i]+s2[j]+byRec(s1,s2,i+1,j+1);

            return min(min(op1,op2),op3);
        }
    }

    int byMem(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){
        if(i>=s1.size() && j>=s2.size()){
            return 0;
        }

        if(i>=s1.size()){
            int ttl=0;
            while(j<s2.size()){
                ttl+=s2[j];
                j++;
            }

            return ttl;
        }

        if(j>=s2.size()){
            int ttl=0;
            while(i<s1.size()){
                ttl+=s1[i];
                i++;
            }

            return ttl;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]){
            return byMem(s1,s2,i+1,j+1,dp);
        }
        else{
            int op1=s1[i]+byMem(s1,s2,i+1,j,dp);
            int op2=s2[j]+byMem(s1,s2,i,j+1,dp);
            // int op3=s1[i]+s2[j]+byMem(s1,s2,i+1,j+1,dp);

            return dp[i][j]=min(op1,op2);
        }
    }

    int byTabu(string &s1,string &s2){
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,0));
        // for(int col=0;col<=s2.size();col++){
        //     int ttl=0;
        //     int j=col;

        //     while(j<s2.size()){
        //         ttl+=s2[j];
        //         j++;
        //     }

        //     dp[s1.size()][col]=ttl;
        // }

        // for(int row=0;row<=s1.size();row++){
        //     int ttl=0;
        //     int i=row;

        //     while(i<s1.size()){
        //         ttl+=s1[i];
        //         i++;
        //     }

        //     dp[row][s2.size()]=ttl;
        // }

        for(int col=s2.size()-1;col>=0;col--){
            dp[s1.size()][col]=s2[col]+dp[s1.size()][col+1];
        }

        for(int row=s1.size()-1;row>=0;row--){
            dp[row][s2.size()]=s1[row]+dp[row+1][s2.size()];
        }

        // dp[s1.size()][s2.size()]=0;

        for(int i=s1.size()-1;i>=0;i--){
            for(int j=s2.size()-1;j>=0;j--){
                if(s1[i]==s2[j]){
                    dp[i][j]=dp[i+1][j+1];
                }
                else{
                    int op1=s1[i]+dp[i+1][j];
                    int op2=s2[j]+dp[i][j+1];
                    // int op3=s1[i]+s2[j]+byMem(s1,s2,i+1,j+1,dp);

                    dp[i][j]=min(op1,op2);
                }
            }
        }

        return dp[0][0];

    }

    int bySO(string&s1,string&s2){
        vector<int>curr(s2.size()+1,0);
         vector<int>next(s2.size()+1,0);

         for(int col=0;col<=s2.size();col++){
            int ttl=0;
            int j=col;

            while(j<s2.size()){
                ttl+=s2[j];
                j++;
            }

            next[col]=ttl;
        }

         for(int i=s1.size()-1;i>=0;i--){
            int ttl=0;
            int row=i;

            while(row<s1.size()){
                ttl+=s1[row];
                row++;
            }

            curr[s2.size()]=ttl;


            for(int j=s2.size()-1;j>=0;j--){
                if(s1[i]==s2[j]){
                    curr[j]=next[j+1];
                }
                else{
                    int op1=s1[i]+next[j];
                    int op2=s2[j]+curr[j+1];
                    // int op3=s1[i]+s2[j]+byMem(s1,s2,i+1,j+1,dp);

                    curr[j]=min(op1,op2);
                }
            }

            next=curr;
        }

        return next[0];
    }
    int minimumDeleteSum(string s1, string s2) {
        // return byRec(s1,s2,0,0);

        // vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        // return byMem(s1,s2,0,0,dp);

        return byTabu(s1,s2);

        // return bySO(s1,s2);
    }
};