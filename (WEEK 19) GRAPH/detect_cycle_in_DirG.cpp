bool checkCyclebyDfs(int src, unordered_map<int,bool> &vis,vector<int> adj[],unordered_map<int,bool>&dfsTrack){
        vis[src]=true;
        dfsTrack[src]=true;
        for(auto it:adj[src]){
            if(!vis[it]){
                // vis[it]=true;
                bool ans = checkCyclebyDfs(it,vis,adj,dfsTrack);
                if(ans) return ans;
            }
            else if(dfsTrack[it]==true){
                return true;
            }
        }
        dfsTrack[src]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        unordered_map<int,bool>visited;
        unordered_map<int,bool>dfsTrack;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool ans=checkCyclebyDfs(i,visited,adj,dfsTrack);
                if(ans) return ans;
            }
        }
        
        return false;
    }