//Approach-1 (Using Same code of DFS Cycle Check in directed Graph)
//T.C : O(V+E)
//S.C : O(V+E)
class Solution {
public:
    bool isCycleDFS(vector<vector<int>>& adj, int u, vector<bool>& visited, vector<bool>& inRecursion) {
        visited[u] = true;
        inRecursion[u] = true;
        
        
        for(int &v : adj[u]) {
            //if not visited, then we check for cycle in DFS
            if(visited[v] == false && isCycleDFS(adj, v, visited, inRecursion))
                return true;
            else if(inRecursion[v] == true)
                return true;
        }
        
        inRecursion[u] = false;
        return false;
        
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<bool> visited(V, false);
        vector<bool> inRecursion(V, false);
        
        for(int i = 0; i<V; i++) {
            if(!visited[i])
                isCycleDFS(graph, i, visited, inRecursion);
        }
        
        vector<int> safeNodes;
        for(int i = 0; i<V; i++) {
            if(!inRecursion[i])
                safeNodes.push_back(i);
        }
        
        return safeNodes;
    }
};


//Approach-2 (Using BFS) (Toplogical Sort)
//T.C : O(V+E)
//S.C : O(V+E)
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();

        vector<vector<int>> adj(V);
        
        
        queue<int> que;
	    vector<int> indegree(V, 0);
	    int count = 0;
	    //1
	    for(int u = 0; u < V; u++) {
	        for(int &v : graph[u]) {
                adj[v].push_back(u);
	            indegree[u]++;
	        }
	    }
	    
	    //2. Fill que, indegree with 0
	    for(int i = 0; i < V; i++) {
	        if(indegree[i] == 0) {
	            que.push(i);
	            count++;
	        }
	    }
	    
	    //3. Simple BFS
        vector<bool> safe(V, false);
	    while(!que.empty()) {
	        int u = que.front();
	        que.pop();
            safe[u] = true;
	        
	        for(int &v : adj[u]) {
	            indegree[v]--;
	            
	            if(indegree[v] == 0) {
	                que.push(v);
	                count++;
	            }
	            
	        }
	    }
	    
	    vector<int> safeNodes;
        for(int i = 0; i < V; i++) {
            if(safe[i]) {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};



class Solution {
  public:
  
    bool dfs(int src,unordered_map<int,bool>&vis,vector<int>adj[]){
        if(vis[src]) return false;
        
        vis[src]=true;
        for(auto it:adj[src]){
            if(dfs(it,vis,adj)==false){
                vis[src]=false;
                return false;
            }
        }
        vis[src]=false;
        
        return true;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int>ans;
        
        unordered_map<int,bool>vis;
        for(int i=0;i<V;i++){
            if(dfs(i,vis,adj)) ans.push_back(i);
        }
        
        return ans;
    }
};


//LAKSHAY BHAIYA
class Solution {
  public:
    bool checkCycledfs(vector<int>adj[],int src,unordered_map<int,bool>&vis,unordered_map<int,bool>&dfstrack,int safenodes[]){
        vis[src]=true;
        dfstrack[src]=true;
        safenodes[src]=0;
        
        for(auto it:adj[src]){
            if(!vis[it]){
                if(checkCycledfs(adj,it,vis,dfstrack,safenodes)==true) return true;
            }
            
            if(dfstrack[it] && vis[it]){
                return true;
            }
        }
        
        dfstrack[src]=false;
        safenodes[src]=1;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int>ans;
        unordered_map<int,bool>vis,dfstrack;
        int safenodes[V]={0};
        
        for(int i=0;i<V;i++){
            if(!vis[i]) checkCycledfs(adj,i,vis,dfstrack,safenodes);
        }
        
        for(int i=0;i<V;i++){
            if(safenodes[i]) ans.push_back(i);
        }
        
        return ans;
    }
};