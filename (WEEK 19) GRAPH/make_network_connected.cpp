

class Solution {
public:

    void dfs(int src,unordered_map<int,bool>&vis,unordered_map<int,vector<int>>&adj){
        vis[src]=true;

        for(auto it:adj[src]){
            if(!vis[it]) dfs(it,vis,adj);
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;

        unordered_map<int,vector<int>>adj;
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        unordered_map<int,bool>vis;
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]) {
                ans++;
                dfs(i,vis,adj);
            }
        }

        return ans-1;
    }
};



class Solution {
public:

    int getParent(vector<int>&parent,int node){
        if(parent[node]==node) return node;

        return parent[node]=getParent(parent,parent[node]);
    }

    void unionSet(int u,int v,vector<int>&parent,vector<int>&rank){
        if(rank[u]<rank[v]){
            parent[u]=v;
            rank[v]++;
        }
        else{
            parent[v]=u;
            rank[u]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>rank(n,0);
        vector<int>parent(n);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        int extraEdges=0;

        for(auto it:connections){
            int u=it[0];
            int v=it[1];

            u=getParent(parent,u);
            v=getParent(parent,v);

            if(u!=v){
                unionSet(u,v,parent,rank);
            }
            else extraEdges++;
        }

        int components=0;
        for(int i=0;i<parent.size();i++){
            if(parent[i]==i) components++;
        }

        return extraEdges >= components-1 ? components-1 : -1;
    }
};