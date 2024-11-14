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



    
   class Solution {
public:

    bool isSafe(int i,int j,int row,int col){
        if(i<0 || j<0 || i>=row || j>=col) return false;
        return true;
    }

    void bfs(int i,int j,vector<vector<char>>& g,vector<vector<bool>>&vis){
        vis[i][j]=true;
        queue<pair<int,int>>q;
        q.push({i,j});

        while(!q.empty()){
            auto front=q.front();
            q.pop();

            int currX=front.first;
            int currY=front.second;

            int dx[4]={1,-1,0,0};
            int dy[4]={0,0,1,-1};

            for(int i=0;i<4;i++){
                int newX=currX+dx[i];
                int newY=currY+dy[i];

                if(isSafe(newX,newY,g.size(),g[0].size()) && !vis[newX][newY] && g[newX][newY]=='1'){
                    q.push({newX,newY});
                    vis[newX][newY]=true;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
        int count=0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    count++;
                    bfs(i,j,grid,vis);
                }
            }
        }

        return count;
    }
};