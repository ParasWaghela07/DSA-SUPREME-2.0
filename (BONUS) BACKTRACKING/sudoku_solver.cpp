class Solution {
public:
        bool isSafe(int row, int col, vector<vector<char>>& board, char value) {
        int n = board.size();

        for(int i=0; i<n; i++) {
            //row check
            if(board[row][i] == value)
                return false;
            
            //col check
            if(board[i][col] == value) 
                return false;

            //3*3 box check
            if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)] == value) 
                return false;
        }

        return true;
    }
    
    bool isSafe(vector<vector<char>>&board,int i,int j,char ch){
        for(int row=0;row<9;row++){
            if(board[row][j]==ch) return false;
        }

        for(int col=0;col<9;col++){
            if(board[i][col]==ch) return false;
        }

        int startRow=3*(i/3);
        int startCol=3*(j/3);

        int endRow=startRow+3;
        int endCol=startCol+3;

        // for(int rowIndex=startRow;rowIndex<endRow;rowIndex++){
        //     for(int colIndex=startCol;colIndex<endCol;colIndex++){
        //         if(board[rowIndex][colIndex]==ch) return false;
        //     }
        // }

        for(int index=0;index<9;index++){
            if(board[startRow+(index/3)][startCol+(index%3)]==ch) return false;
        }

        return true;
                
    }
    bool solve(vector<vector<char>>&board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char ch='1';ch<='9';ch++){
                        if(isSafe(board,i,j,ch)){
                            board[i][j]=ch;
                            bool ans=solve(board);
                            if(ans) return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        return;
    }
};