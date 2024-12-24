class Solution {
public:
    --brute force approach--O(N*N)--TLE--
    int bfs(int src,unordered_set<int>&vis,unordered_map<int,vector<int>>&adj){
        queue<int>q;
        q.push(src);
        vis.insert(src);
        int level=0;

        while(!q.empty()){
            int n=q.size();
            while(n--){
                int front=q.front();
                q.pop();

                for(auto it:adj[front]){
                    if(vis.find(it)!=vis.end()) continue;

                    q.push(it);
                    vis.insert(it);
                }
            }

            level++;
        }

        return level-1;
    }
    int dfs(int src,unordered_set<int>&vis,unordered_map<int,vector<int>>&adj){
        int ans=0;
        vis.insert(src);

        for(auto it:adj[src]){
            if(vis.find(it)==vis.end()){
                int temp=1+dfs(it,vis,adj);
                ans=max(ans,temp);
            }
        }

        return ans;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size()+1;
        int m=edges2.size()+1;

        unordered_map<int,vector<int>>adj1;
        unordered_map<int,vector<int>>adj2;

        for(auto it:edges1){
            adj1[it[0]].push_back(it[1]);
            adj1[it[1]].push_back(it[0]);
        }

        for(auto it:edges2){
            adj2[it[0]].push_back(it[1]);
            adj2[it[1]].push_back(it[0]);
        }

        int mini1=n-1;
        int tree1_max=INT_MIN;
        
        for(int i=0;i<n;i++){
            unordered_set<int>vis;
            int temp=bfs(i,vis,adj1);
            
            tree1_max=max(tree1_max,temp);
            mini1=min(mini1,temp);
        }

        int tree2_max=INT_MIN;
        int mini2=m-1;
        for(int i=0;i<m;i++){
            unordered_set<int>vis;
            int temp=bfs(i,vis,adj2);

            tree2_max=max(tree2_max,temp);
            mini2=min(mini2,temp);
        }

        int conn=mini1+mini2+1;
       
        return max(max(tree1_max,tree2_max),conn);
    }
};

---OPTIMAL--2*O(N+M)-/ 2*O(V+E)
class Solution {
public:
    pair<int,int> bfs(int src,unordered_map<int,vector<int>>&adj){
        queue<int>q;
        q.push(src);
        
        unordered_map<int,bool>vis;
        vis[src]=true;
        int level=0;
        int EndNode=src;

        while(!q.empty()){
            int n=q.size();
            while(n--){
                int node=q.front();
                q.pop();

                EndNode=node;
                for(auto it:adj[node]){
                    if(!vis[it]){
                        q.push(it);
                        vis[it]=true;
                    }
                }
            }

            if(!q.empty()) level++;
        }

        return {EndNode,level};
    }
    int getdiameter(unordered_map<int,vector<int>>&adj){
        pair<int,int>FirstEnd=bfs(0,adj);
        pair<int,int>SecondEnd=bfs(FirstEnd.first,adj);

        return SecondEnd.second;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int,vector<int>>adj1,adj2;
        for(auto it:edges1){
            adj1[it[0]].push_back(it[1]);
            adj1[it[1]].push_back(it[0]);
        }

        for(auto it:edges2){
            adj2[it[0]].push_back(it[1]);
            adj2[it[1]].push_back(it[0]);
        }

        int diameter1=getdiameter(adj1);
        int diameter2=getdiameter(adj2);

        int merged_diameter=(diameter1+1)/2 + (diameter2+1)/2 + 1;

        return max(diameter1,max(diameter2,merged_diameter));
    }
};