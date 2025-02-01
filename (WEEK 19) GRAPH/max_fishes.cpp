class Solution {
public:
    class DSU{
        public:
        vector<int>parent;
        vector<int>size;

        DSU(int n,vector<vector<int>>&grid){
            parent.resize(n);
            size.resize(n);

            for(int i=0;i<n;i++){
                parent[i]=i;
            }
            int row=grid.size();
            int col=grid[0].size();
            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    if(grid[i][j]==0) continue;
                    int index=(i*col)+j;
                    size[index]=grid[i][j];
                }
            }
        }

        int find(int x){
            if(x==parent[x]) return x;

            return parent[x]=find(parent[x]);
        }

        void Union(int x,int y){
            int x_p=find(x);
            int y_p=find(y);

            if(x_p==y_p) return;

            if(size[x_p]>size[y_p]){
                size[x_p]+=size[y_p];
                parent[y_p]=x_p;
            }
            else if(size[x_p]<size[y_p]){
                size[y_p]+=size[x_p];
                parent[x_p]=y_p;
            }
            else{
                size[x_p]+=size[y_p];
                parent[y_p]=x_p;
            }
        }

        int getMax(){
            int ans=0;
            for(auto it:size){
                ans=max(ans,it);
            }
            return ans;
        }
    };
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        DSU dsu(n*m,grid);

        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) continue;

                for(int k=0;k<4;k++){
                    int i_=i+dx[k];
                    int j_=j+dy[k];

                    if(i_>=0 && j_>=0 && i_<n && j_<m && grid[i_][j_]!=0){
                        int xindex=(i*m)+j;
                        int yindex=(i_*m)+j_;

                        dsu.Union(xindex,yindex);
                    }
                }

            }
        }

        int ans=dsu.getMax();
        return ans;
    }
};