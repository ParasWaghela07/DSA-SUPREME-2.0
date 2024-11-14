class Solution {
public:

    bool isSafe(int i,int j,int row,int col){
        return i>=0 && j>=0 && i<row && j<col;
    }
    int orangesRotting(vector<vector<int>>& g) {
        
        int ans=0;

        vector<vector<int>>grid=g;
        queue<pair<int,pair<int,int>>>q;
        int freshOnes=0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                }
                if(grid[i][j]==1) freshOnes++;
            }
        }

        while(!q.empty()){
            auto front=q.front();
            q.pop();

            int currTime=front.first;
            int currX=front.second.first;
            int currY=front.second.second;

            int dx[4]={1,-1,0,0};
            int dy[4]={0,0,1,-1};

            for(int i=0;i<4;i++){
                int newX=currX+dx[i];
                int newY=currY+dy[i];

                if(isSafe(newX,newY,grid.size(),grid[0].size()) && grid[newX][newY]==1){
                        freshOnes--;
                        grid[newX][newY]=2;
                        q.push({currTime+1,{newX,newY}});
                        ans=currTime+1;
                        // ans=max(ans,currTime+1);
                }
            }
        }

        if(freshOnes>0) return -1;

        return ans;
    }
};

class Solution {
public:

    void dfs(int i,int j,vector<vector<int>>&g,int minTime){
        if(i<0 || j<0 || i>=g.size() ||j>=g[0].size() ||g[i][j]==0)return;
        if(g[i][j]>1 && g[i][j]<minTime) return;

        g[i][j]=minTime;
        dfs(i+1,j,g,minTime+1);
        dfs(i-1,j,g,minTime+1);
        dfs(i,j+1,g,minTime+1);
        dfs(i,j-1,g,minTime+1);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>>g=grid;
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[0].size();j++){
                if(g[i][j]==2){
                    dfs(i,j,g,2);
                }
            }
        }

        int ans=2;

        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[0].size();j++){
                if(g[i][j]==1) return -1;
                ans=max(ans,g[i][j]);                
            }
        }

        return ans-2;
    }
};


// class Solution {
// public:

//     bool isSafe(int i,int j,int row,int col){
//         return i>=0 && j>=0 && i<row && j<col;
//     }
//     int orangesRotting(vector<vector<int>>& grid) {
//         vector<vector<int>>dist(grid.size(),vector<int>(grid[0].size(),INT_MAX));

//         queue<pair<int,pair<int,int>>>q;
//         int freshOnes=0;

//         for(int i=0;i<grid.size();i++){
//             for(int j=0;j<grid[0].size();j++){
//                 if(grid[i][j]==2){
//                     q.push({0,{i,j}});
//                     dist[i][j]=0;
//                 }
//                 if(grid[i][j]==1) freshOnes++;
//             }
//         }

//         while(!q.empty()){
//             auto front=q.front();
//             q.pop();

//             int currTime=front.first;
//             int currX=front.second.first;
//             int currY=front.second.second;

//             int dx[4]={1,-1,0,0};
//             int dy[4]={0,0,1,-1};

//             for(int i=0;i<4;i++){
//                 int newX=currX+dx[i];
//                 int newY=currY+dy[i];

//                 if(isSafe(newX,newY,grid.size(),grid[0].size()) && grid[newX][newY]!=0){
//                     if(grid[newX][newY]==1){
//                         freshOnes--;
//                         grid[newX][newY]=2;
//                         dist[newX][newY]=currTime+1;
//                         q.push({currTime+1,{newX,newY}});
//                     }
//                     else if(currTime+1 < dist[newX][newY]){
//                         dist[newX][newY]=currTime+1;
//                         q.push({currTime+1,{newX,newY}});
//                     }
//                 }
//             }
//         }

//         if(freshOnes>0) return -1;

//         int ans=0;
//         for(int i=0;i<dist.size();i++){
//             for(int j=0;j<dist[0].size();j++){
//                 if(grid[i][j]!=0) ans=max(ans,dist[i][j]);
//             }
//         }

//         return ans;
//     }
// };