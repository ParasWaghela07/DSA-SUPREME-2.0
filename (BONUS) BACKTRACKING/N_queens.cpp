class Solution {
public:
    unordered_map<int,bool>row;
    unordered_map<int,bool>digd;
    unordered_map<int,bool>digu;

    bool isSafe(int rowIndex,int colIndex){
        if(row[rowIndex] || digd[rowIndex+colIndex] || digu[rowIndex-colIndex]) return false;

        return true;
    }

    void fillAns(vector<vector<char>>&grid,vector<vector<string>>&ans){
        vector<string>temp1;
        for(int i=0;i<grid.size();i++){
            string temp2;
            for(int j=0;j<grid[0].size();j++){
                temp2.push_back(grid[i][j]);
            }
            temp1.push_back(temp2);
        }
        ans.push_back(temp1);
    }

    void solve(vector<vector<char>>&grid,vector<vector<string>>&ans,int &n,int col){
        if(col>=n){
             fillAns(grid,ans);
             return;
        }

        for(int rowIndex=0;rowIndex<n;rowIndex++){
            if(isSafe(rowIndex,col)){
                row[rowIndex]=1;
                digd[rowIndex+col]=1;
                digu[rowIndex-col]=1;
                grid[rowIndex][col]='Q';
                solve(grid,ans,n,col+1);
                row[rowIndex]=0;
                digd[rowIndex+col]=0;
                digu[rowIndex-col]=0;
                grid[rowIndex][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>>grid(n,vector<char>(n,'.'));
        vector<vector<string>>ans;
        solve(grid,ans,n,0);
        return ans;
    }
};







class Solution {
public:
    unordered_map<int,bool>rowCheck;
    unordered_map<int,bool>topdig;
    unordered_map<int,bool>bottomdig;
    // bool isSafe(int i,int j,vector<vector<char>>&board){
    //     int row=board.size();
    //     int col=board[0].size();

    //     int tempX=i;
    //     int tempY=j;

    //     while(tempY>=0){
    //         if(board[tempX][tempY]=='Q'){
    //             return false;
    //         }
    //         tempY--;
    //     }

    //     tempY=j;

    //     while(tempX>=0 && tempY>=0){
    //         if(board[tempX][tempY]=='Q'){
    //             return false;
    //         }
    //         tempX--;
    //         tempY--;
    //     }

    //     tempX=i;
    //     tempY=j;

    //     while(tempX<row && tempY>=0){
    //         if(board[tempX][tempY]=='Q'){
    //             return false;
    //         }
    //         tempX++;
    //         tempY--;
    //     }

    //     return true;
    // }

    bool isSafe(int i,int j,vector<vector<char>>&board){
        if(rowCheck[i]==true){
            return false;
        }
        else if(topdig[j-i]==true){
            return false;
        }
        else if(bottomdig[j+i]==true){
            return false;
        }

        return true;
    }

    void storeAns(vector<vector<char>>&board,vector<vector<string>>&ans,int &n){
        vector<string>v;
        for(int i=0;i<n;i++){
            string temp="";
            for(int j=0;j<n;j++){
                temp+=board[i][j];
            }
            v.push_back(temp);
        }
        ans.push_back(v);
    }
    // void solve(vector<vector<char>>&board,int col,vector<vector<string>>&ans,int &n){
    //     if(col>=n){
    //         storeAns(board,ans,n);
    //         return;
    //     }

    //     for(int row=0;row<n;row++){
    //         if(isSafe(row,col,board)){
    //             board[row][col]='Q';
    //             solve(board,col+1,ans,n);
    //             board[row][col]='.';
    //         }
    //     }
    // }
    void solve(vector<vector<char>>&board,int col,vector<vector<string>>&ans,int &n){
        if(col>=n){
            storeAns(board,ans,n);
            return;
        }

        for(int row=0;row<n;row++){
            if(isSafe(row,col,board)){
                board[row][col]='Q';
                rowCheck[row]=true;
                topdig[col-row]=true;
                bottomdig[col+row]=true;

                solve(board,col+1,ans,n);

                board[row][col]='.';
                rowCheck[row]=false;
                topdig[col-row]=false;
                bottomdig[col+row]=false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>>board(n,vector<char>(n,'.'));
        int col=0;

        vector<vector<string>>ans;

        solve(board,0,ans,n);

        return ans;
    }
};