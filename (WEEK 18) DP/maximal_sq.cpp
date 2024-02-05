 int byMemo(int i,int j,int &row,int &col,int &maxi,vector<vector<char>>& matrix,vector<vector<int>>&dp){
        if(i>=row || j>=col){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right=byMemo(i,j+1,row,col,maxi,matrix,dp);
        int diag=byMemo(i+1,j+1,row,col,maxi,matrix,dp);
        int down=byMemo(i+1,j,row,col,maxi,matrix,dp);
        if(matrix[i][j]=='1'){
            int ans=1+min(min(right,down),diag);
            maxi=max(maxi,ans);
            return dp[i][j]=ans;
        }
        else{
            return 0;
        }
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int i=0;
        int j=0;
        int row=matrix.size();
        int col=matrix[0].size();
        int maxi=0;
        // int ans=byRecursion(i,j,row,col,maxi,matrix);
        vector<vector<int>>dp(row+1,vector<int>(col+1,-1));
        int ans=byMemo(i,j,row,col,maxi,matrix,dp);

        return maxi*maxi;
    }
