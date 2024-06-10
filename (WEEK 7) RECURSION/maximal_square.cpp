class Solution {
public:
    int solve(vector<vector<char>>&m , int &row,int &col,int i,int j,int &maxi){
        if(i>=row || j>=col) return 0;

        int right=solve(m,row,col,i,j+1,maxi);
        int down=solve(m,row,col,i+1,j,maxi);
        int dig=solve(m,row,col,i+1,j+1,maxi);

        if(m[i][j]=='1'){
            int ans = 1 + min(right,min(down,dig));
            maxi=max(maxi,ans);
            return ans;
        }
        else{
            return 0;
        }
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();

        int maxi=0;
        int ans=solve(matrix,row,col,0,0,maxi);
        return maxi*maxi;
    }
};