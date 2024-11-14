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