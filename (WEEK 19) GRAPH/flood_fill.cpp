class Solution {
public:
    void dfs(vector<vector<int>>&ans,int i,int j,int color,int initcolor){
        if(i<0 || j<0 || i>=ans.size() || j>=ans[0].size() || ans[i][j]!=initcolor) return;

        ans[i][j]=color;
        dfs(ans,i+1,j,color,initcolor);
        dfs(ans,i-1,j,color,initcolor);
        dfs(ans,i,j+1,color,initcolor);
        dfs(ans,i,j-1,color,initcolor);
    }

    bool isSafe(int i,int j,int row,int col){
        return i>=0 && j>=0 && i<row && j<col;
    }

    void bfs(vector<vector<int>>&ans,int i,int j,int color,int initcolor){
        queue<pair<int,int>>q;
        ans[i][j]=color;
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

                if(isSafe(newX,newY,ans.size(),ans[0].size()) && ans[newX][newY]==initcolor){
                    q.push({newX,newY});
                    ans[newX][newY]=color;
                }
            }
        }
    }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        vector<vector<int>>ans=image;
        bfs(ans,sr,sc,color,ans[sr][sc]);
        return ans;
    }
};