class Solution {
    public:
    LC-1976
        int mod=1e9+7;
        int bfs(int &n,int src,int des,unordered_map<int,vector<pair<int,int>>>&adj){
            priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>>pq;
            vector<long long>dist(n,LLONG_MAX);
            vector<long long>ways(n,0);
    
            pq.push({0,src});
            dist[0]=0;
            ways[0]=1;
    
            while(!pq.empty()){
                auto top=pq.top();
                pq.pop();
    
                long long cost=top.first;
                int node=top.second;
    
    
                for(auto &it:adj[node]){
                    if(cost+it.second < dist[it.first]){
                        pq.push({cost+it.second,it.first});
                        dist[it.first]=cost+it.second;
                        ways[it.first]=ways[node];
                    }
                    else if(cost+it.second == dist[it.first]){
                        ways[it.first]=(ways[node]+ways[it.first])%mod;
                    }
                }
            }
    
            return ways[des];
        }
        int countPaths(int n, vector<vector<int>>& roads) {
            unordered_map<int,vector<pair<int,int>>>adj;
            for(auto it:roads){
                adj[it[0]].push_back({it[1],it[2]});
                adj[it[1]].push_back({it[0],it[2]});
            }
            return bfs(n,0,n-1,adj);
        }
    };