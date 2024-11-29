class Solution {
public:
    bool isValid(int newX,int newY,int n,int m){
        return newX>=0 && newX<n && newY>=0 && newY<m;
    }
    int minimumTime(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        if(grid[0][1]>1 && grid[1][0]>1) return -1;

        pq.push({0,0,0});
        dist[0][0]=0;

        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();

            int currTime=top[0];
            int currX=top[1];
            int currY=top[2];

            int dx[4]={1,-1,0,0};
            int dy[4]={0,0,1,-1};

            for(int i=0;i<4;i++){
                int newX=currX+dx[i];
                int newY=currY+dy[i];

                if(isValid(newX,newY,n,m)){
                    ----------- WE CAN USE ANOTHER 2D VISITED ARRAY BECAUSE IN THIS QST WHOEVER TOUCHES ANY CELL 1ST WILL PROVIDE SHORTEST DISTANCE
                    THEREFOR WE CAN DIRECTLY SKIP VISITED NODES TO PREVENT COMPARING MULTIPLE DISTANCES ON ANY CELL-----ELSE BELOW
                    
                     
                    if(currTime+1>=grid[newX][newY] && currTime+1<dist[newX][newY]){
                        dist[newX][newY]=currTime+1;
                        pq.push({currTime+1,newX,newY});
                    }
                    else if(currTime+1<grid[newX][newY]){
                        int newTime;
                        if((currTime&1 && grid[newX][newY]&1) || (!(currTime&1) && !(grid[newX][newY]&1))){
                            newTime=grid[newX][newY]+1;
                        }
                        else{
                            newTime=grid[newX][newY];
                        }

                        if(dist[newX][newY]>newTime){
                            dist[newX][newY]=newTime;
                            pq.push({newTime,newX,newY});
                        }
                    }
                }
            }
        }

        return dist[n-1][m-1];
    }
};