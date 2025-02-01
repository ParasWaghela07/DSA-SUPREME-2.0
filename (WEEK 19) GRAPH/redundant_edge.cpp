

class Solution {
public:
    class DSU{
        public:
        vector<int>parent;
        vector<int>rank;

        DSU(int n){
            this->parent.resize(n+1);
            this->rank.resize(n+1);

            for(int i=1;i<=n;i++){
                parent[i]=i;
                rank[i]=0;
            }
        }

        int findParent(int x){
            if(x==parent[x]) return x;

            return parent[x]=findParent(parent[x]);
        }

        void Union(int x,int y){
            int x_p=findParent(x);
            int y_p=findParent(y);

            if(rank[x_p]>rank[y_p]){
                parent[y_p]=x_p;
            }
            else if(rank[x_p]<rank[y_p]){
                parent[x_p]=y_p;
            }
            else{
                 parent[y_p]=x_p;
                 rank[x_p]++;
            }
        }
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size());
        for(auto it:edges){
            int u=it[0];
            int v=it[1];

            if(dsu.findParent(u)==dsu.findParent(v)) return it;
            dsu.Union(u,v);

        }

        return {};
    }
};

class Solution {
public:
    //O(n^2) time complexity
    bool dfs(unordered_map<int,vector<int>>&adj,int u,int v,unordered_map<int,bool>&vis){
        vis[u]=1;
        if(u==v) return true;

        for(auto it:adj[u]){
            if(!vis[it]){
                if(dfs(adj,it,v,vis)) return true;
            }
        }

        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        for(auto it:edges){
            unordered_map<int,bool>vis;
            if(adj.find(it[0])!=adj.end() && adj.find(it[1])!=adj.end() && dfs(adj,it[0],it[1],vis)) return it;

            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        return {};
    }
};