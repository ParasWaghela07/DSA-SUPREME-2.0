// BY BFS

bool checkcyclebyBfs(int &src,unordered_map<int,bool>&vis,vector<int>adj[]){
        queue<int>q;
        unordered_map<int,int>parent;
        q.push(src);
        vis[src]=true;
        parent[src]=-1;
        
        while(!q.empty()){
            int front=q.front();
            q.pop();
            
            for(auto it:adj[front]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=true;
                    parent[it]=front;
                }
                else if(it!=parent[front]){
                    return true;
                }
            }
        }
        
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        unordered_map<int,bool>visited;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool ans=checkcyclebyBfs(i,visited,adj);
                if(ans==true) return true;
            }
        }
        
        return false;
        
    }

    //BY DFS

    bool checkcyclebyDfs(int src,unordered_map<int,bool>&vis,vector<int>adj[],int parent){
        vis[src]=true;
        for(auto it:adj[src]){
            if(!vis[it]){
                // vis[it]=true;
                bool ans = checkcyclebyDfs(it,vis,adj,src);
                if(ans) return ans;
            }
            else if(it!=parent){
                return true;
            }
        }
        
        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        unordered_map<int,bool>visited;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool ans=checkcyclebyDfs(i,visited,adj,-1);
                if(ans==true) return true;
            }
        }
        
        return false;
        
    }