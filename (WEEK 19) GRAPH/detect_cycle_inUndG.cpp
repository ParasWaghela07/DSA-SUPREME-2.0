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
                if(it==parent[front]) continue; // FLAG 1 if we uuse this then remove FLAG2 and just return true in else condition
                if(!vis[it]){
                    q.push(it);
                    vis[it]=true;
                    parent[it]=front;
                }
                else if(it!=parent[front]){ // FLAG 2 if we use this then remove FLAG1
                    return true;
                }
                // else if(parent[it]!=-1 && parent[it]!=front){ ---------why not this
                //     return true;
                // }
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
            if(it==parent) continue; // if we do not write this then uncomment last else if also remove last 'else' 
            if(!vis[it]){
                // vis[it]=true;
                bool ans = checkcyclebyDfs(it,vis,adj,src);
                if(ans) return ans;
            }
            else return true;
            // else if(it!=parent){
            //     return true;
            // }
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