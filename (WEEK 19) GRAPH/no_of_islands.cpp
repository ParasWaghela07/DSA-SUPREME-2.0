class Solution {
public:
    void dfs(vector<vector<char>>&grid,int i,int j,int &row,int &col){
        if( i>=row || j>=col || i<0 || j<0 || grid[i][j]=='0'||grid[i][j]=='-'){
            return;
        }
        grid[i][j]='-';
        dfs(grid,i+1,j,row,col);
        dfs(grid,i-1,j,row,col);
        dfs(grid,i,j+1,row,col);
        dfs(grid,i,j-1,row,col);
    }
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int ans=0;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]!='-' && grid[i][j]!='0'){
                    dfs(grid,i,j,row,col);
                    ans++;
                }
            }
        }

        return ans;
    }



    
    bool isSafe(int &newX,int &newY,int &row,int &col,vector<vector<char>>&temp){
        if(newX>=0 && newY>=0 && newX<row && newY<col && temp[newX][newY]=='1'){
            return true;
        }
        else{
            return false;
        }
    }
    void bfs(vector<vector<char>>&temp,int &i,int &j,int &row,int &col){
        queue<pair<int,int>>q;
        q.push({i,j});

        while(!q.empty()){
            pair<int,int>front=q.front();
            q.pop();

            int currX=front.first;
            int currY=front.second;

            int dx[]={1,0,-1,0};
            int dy[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int newX=currX+dx[i];
                int newY=currY+dy[i];

                if(isSafe(newX,newY,row,col,temp)){
                    q.push({newX,newY});
                    temp[newX][newY]='0';
                }

            }
        }
    }
    int numIslands(vector<vector<char>>&grid){
        vector<vector<char>>temp=grid;
        int row=grid.size();
        int col=grid[0].size();
        int count=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(temp[i][j]=='1'){
                    bfs(temp,i,j,row,col);
                    count++;
                }
            }
        }

        return count;
    }
};