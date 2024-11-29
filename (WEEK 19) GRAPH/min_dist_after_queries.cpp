class Solution {
public:
    --LEETCODE 3243--
    int bfs(int n,unordered_map<int,vector<int>>&mp){
        unordered_set<int>vis;
        queue<pair<int,int>>q;
        vis.insert(0);
        q.push({0,0});

        while(!q.empty()){
            int t=q.size();
            while(t--){
            auto front=q.front();
            q.pop();

            int node=front.first;
            int dist=front.second;

            if(node==n-1) return dist;

            for(auto it:mp[node]){
                int nextNode=it;
                int nextDist=dist+1;
                if(vis.find(nextNode)==vis.end()){
                    q.push({nextNode,nextDist});
                    vis.insert(nextNode);
                }
            }
        }
        }

        return -1;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {

       unordered_map<int,vector<int>>mp;
       for(int i=0;i<n-1;i++){
        mp[i].push_back(i+1);
       } 

       vector<int>ans;

       for(auto it:queries){
        int u=it[0];
        int v=it[1];

        mp[u].push_back(v);

        int miniDist=bfs(n,mp);
        ans.push_back(miniDist);
       }

       return ans;
    }
};


class Solution {
public:
    int dijkstra(unordered_map<int,vector<pair<int,int>>>&adj,int n){
        vector<int>dist(n,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        pq.push({0,0});
        dist[0]=0;

        while(!pq.empty()){
            int currdist=pq.top().first;
            int currnode=pq.top().second;
            pq.pop();

            for(auto it:adj[currnode]){
                int nextNode=it.first;
                int wt=it.second;

                if(currdist+wt < dist[nextNode]){
                    dist[nextNode]=currdist+wt;
                    pq.push({currdist+wt,nextNode});
                }
            }
        }

        return dist[n-1];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(int i=0;i<n-1;i++){
            adj[i].push_back({i+1,1});
        }

        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int u=queries[i][0];
            int v=queries[i][1];

            adj[u].push_back({v,1});
            int dist=dijkstra(adj,n);

            ans.push_back(dist);
        }

        return ans;
    }
};