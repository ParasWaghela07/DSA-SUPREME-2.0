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