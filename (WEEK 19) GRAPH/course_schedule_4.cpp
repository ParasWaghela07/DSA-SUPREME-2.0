

class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& qu) {
        unordered_map<int,vector<int>>adj;
        vector<int>indeg(n,0);
        for(auto it:pre){
            adj[it[0]].push_back(it[1]);
            indeg[it[1]]++;
        }

        unordered_map<int,unordered_set<int>>mp;
        queue<int>q;

        for(int i=0;i<n;i++) if(indeg[i]==0) q.push(i);

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto &it:adj[node]){
                indeg[it]--;

                mp[it].insert(node);
                for(auto &p:mp[node]){
                    mp[it].insert(p);
                }

                if(indeg[it]==0) q.push(it);
            }
        }

        vector<bool>ans;
        for(auto &it:qu){
            if(mp[it[1]].contains(it[0])) ans.push_back(true);
            else ans.push_back(false);
        }

        return ans;
    }
};

class Solution {
public:
    void dfs(int src,int des,unordered_map<int,vector<int>>&adj,vector<vector<bool>>&v,vector<bool>&vis){
        vis[src]=1;
        v[src][des]=true;
        for(auto it:adj[des]) if(!vis[it]) dfs(src,it,adj,v,vis);
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& q) {
        unordered_map<int,vector<int>>adj;
        for(auto it:pre) adj[it[0]].push_back(it[1]);

        vector<vector<bool>>v(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            vector<bool>vis(n,false);
            dfs(i,i,adj,v,vis);
        }
        vector<bool>ans;
        for(auto it:q) ans.push_back(v[it[0]][it[1]]);
        return ans;
    }
};

class Solution {
public:
    bool dfs(int src,unordered_map<int,vector<int>>&adj,int des,vector<bool>&vis){
        vis[src]=1;
        if(src==des) return true;
        for(auto it:adj[src]){
            if(!vis[it]) if(dfs(it,adj,des,vis)==true) return true;
        }

        return false;
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& q) {
        unordered_map<int,vector<int>>adj;
        for(auto it:pre) adj[it[0]].push_back(it[1]);

        vector<vector<bool>>v(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                vector<bool>vis(n,false);
                v[i][j]=dfs(i,adj,j,vis);
            }
        }
        vector<bool>ans;
        for(auto it:q) ans.push_back(v[it[0]][it[1]]);
        return ans;
    }
};

class Solution {
public:
    bool dfs(int src,unordered_map<int,vector<int>>&adj,int des,vector<bool>&vis){

        if(src==des) return true;
        vis[src]=1;
        for(auto it:adj[src]){
            if(!vis[it] && dfs(it,adj,des,vis)==true) return true;
        }

        return false;
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& q) {
        unordered_map<int,vector<int>>adj;
        for(auto it:pre){
            adj[it[0]].push_back(it[1]);
        }

        vector<bool>ans;
        for(auto it:q){
            int u=it[0];
            int v=it[1];
            vector<bool>vis(n,false);
            ans.push_back(dfs(u,adj,v,vis));
        }
        return ans;
    }
};