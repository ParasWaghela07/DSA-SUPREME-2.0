int byRecursion(int i,int j,int &row,int &col,int &maxi,vector<vector<char>>& matrix){
        if(i>=row || j>=col){
            return 0;
        }
        int right=byRecursion(i,j+1,row,col,maxi,matrix);
        int diag=byRecursion(i+1,j+1,row,col,maxi,matrix);
        int down=byRecursion(i+1,j,row,col,maxi,matrix);
        if(matrix[i][j]=='1'){
            int ans=1+min(min(right,down),diag);
            maxi=max(maxi,ans);
            return ans;
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
        int ans=byRecursion(i,j,row,col,maxi,matrix);

        return maxi*maxi;
    }