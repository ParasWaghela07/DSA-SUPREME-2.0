class Solution {
public:
    void dfs(int i,int j,int &oldcolor,int &newcolor,vector<vector<int>>&image,int &row,int &col){
        if(i<0 || j<0 || i>=row || j>=col || image[i][j]!=oldcolor){
            return;
        }

        image[i][j]=newcolor;
        dfs(i+1,j,oldcolor,newcolor,image,row,col);
        dfs(i-1,j,oldcolor,newcolor,image,row,col);
        dfs(i,j+1,oldcolor,newcolor,image,row,col);
        dfs(i,j-1,oldcolor,newcolor,image,row,col);
    }
    bool isSafe(int &newX,int &newY,vector<vector<int>>&image,int &row,int &col,int &oc){
        if(newX>=0 && newY>=0 && newX<row && newY<col && image[newX][newY]==oc){
            return true;
        }
        else{
            return false;
        }
    }
    void bfs(int &i,int &j,int &oldcolor,int &newcolor,vector<vector<int>>&image,int &row,int &col){
        queue<pair<int,int>>q;
        q.push({i,j});
        image[i][j]=newcolor;

        while(!q.empty()){
            auto front=q.front();
            q.pop();

            int currX=front.first;
            int currY=front.second;

            int dx[]={1,-1,0,0};
            int dy[]={0,0,1,-1};

            for(int i=0;i<4;i++){
                int newX=currX+dx[i];
                int newY=currY+dy[i];

                if(isSafe(newX,newY,image,row,col,oldcolor)){
                    q.push({newX,newY});
                    image[newX][newY]=newcolor;
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //CAN MAKE COPY IN ANS BUT NOW AM EDITING OG ARRAY DUE TO QST 
        int row=image.size();
        int col=image[0].size();
        int oldColor=image[sr][sc];

        if(oldColor==color) return image;

        //dfs(sr,sc,oldColor,color,image,row,col);

        bfs(sr,sc,oldColor,color,image,row,col);

        return image;
    }
};