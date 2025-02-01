class Solution {
public:
    --leetcode-1368--
    bool isValid(vector<vector<int>>&dist,int i,int j,int n,int m,int cost){
        if(i<0 || j<0 || i>=n || j>=m) return false;
        if(cost >= dist[i][j]) return false;
        return true;
    }
    int minCost(vector<vector<int>>& grid) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,0,0});
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();

            int cost=top[0];
            int currX=top[1];
            int currY=top[2];

            if(currX==n-1 && currY==m-1) return cost;

            int dx[4]={0,0,1,-1};
            int dy[4]={1,-1,0,0};

            for(int i=0;i<4;i++){
                int dir=i+1;
                int newX=currX+dx[i];
                int newY=currY+dy[i];

                int extra=grid[currX][currY]==dir ?0:1;
                int newCost=extra+cost;

                if(isValid(dist,newX,newY,n,m,newCost)){
                    pq.push({newCost,newX,newY});
                    dist[newX][newY]=newCost;
                }
            }
        }

        return 0;
    }
};

class Solution {
public:
    vector<vector<int>> dir={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m, n;
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited, int cost) {
        if(i == m-1 && j == n-1) { //reached destination
            return cost;
        }

        visited[i][j] = true;

        //explore
        int minCost = INT_MAX;
        for(int dir_i = 0; dir_i <= 3; dir_i++) {
            int i_ = i + dir[dir_i][0];
            int j_ = j + dir[dir_i][1];

            if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !visited[i_][j_]) {
                int nextCost = cost + ((grid[i][j]-1 != dir_i) ? 1 : 0);
                
                minCost = min(minCost, dfs(i_, j_, grid, visited, nextCost));
            }
        }

        visited[i][j] = false;
        return minCost;
    }

    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        return dfs(0, 0, grid, visited, 0);//explore all paths by backtracking
    }
};