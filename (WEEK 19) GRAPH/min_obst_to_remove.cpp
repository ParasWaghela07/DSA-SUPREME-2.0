class Solution {
public:
    bool isValid(int newX,int newY,int n,int m){
        return newX>=0 && newX<n && newY>=0 && newY<m;
    }
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        set<pair<int,int>>vis;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        pq.push({0,0,0});

        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();

            int currRemovals=top[0];
            int currX=top[1];
            int currY=top[2];

            int dx[4]={1,-1,0,0};
            int dy[4]={0,0,1,-1};

            for(int i=0;i<4;i++){
                int newX=currX+dx[i];
                int newY=currY+dy[i];

                if(isValid(newX,newY,n,m) && dist[newX][newY]>currRemovals){
                    dist[newX][newY]=currRemovals;
                    if(grid[newX][newY]==0) pq.push({currRemovals,newX,newY});
                    else pq.push({currRemovals+1,newX,newY});
                }
            }
        }

        return dist[n-1][m-1];
    }
};


--DIJKSTRA
class Solution {
public:
    bool isValid(int newX,int newY,int n ,int m){
        return newX>=0 && newY>=0 && newX<n && newY<m;
    }
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>dist(n,vector<int>(m,1e9));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;

        pq.push({0,0,0});
        dist[0][0]=0;

        while(!pq.empty()){
            int currdist=pq.top()[0];
            int currX=pq.top()[1];
            int currY=pq.top()[2];

            pq.pop();

            int dx[4]={1,-1,0,0};
            int dy[4]={0,0,1,-1};

            for(int i=0;i<4;i++){
                int newX=currX+dx[i];
                int newY=currY+dy[i];

                if(isValid(newX,newY,n,m)){
                    int wt=grid[newX][newY];

                    if(currdist+wt < dist[newX][newY]){
                        dist[newX][newY]=currdist+wt;
                        pq.push({currdist+wt,newX,newY});
                    }
                }
            }
        }

        return dist[n-1][m-1];
    }
};