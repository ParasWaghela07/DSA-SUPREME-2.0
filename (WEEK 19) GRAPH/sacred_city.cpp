class Solution {
public:
--- DJIKSTRA ACCEPTED
    int djikstra(int n,int src,unordered_map<int,vector<pair<int,int>>>&adj,int &limit){
        vector<int>dist(n,INT_MAX);
        set<pair<int,int>>st;
        st.insert({0,src});
        dist[src]=0;

        int reachable=0;

        while(!st.empty()){
            auto top=*st.begin();
            st.erase(st.begin());

            int currNode=top.second;
            int currDist=top.first;

            if(currNode!=src && currDist <=limit) reachable++;

            for(auto it:adj[currNode]){
                int v=it.first;
                int wt=it.second;

                if(currDist+wt<dist[v]){
                                        auto prevEntry=st.find({dist[v],v});
                    if(prevEntry!=st.end()){
                        st.erase(prevEntry);
                    }

                    st.insert({currDist+wt,v});
                    dist[v]=currDist+wt;
                }
            }
            }

            return reachable;
        }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        int ans=0;
        int ansCount=INT_MAX;

        for(int i=0;i<n;i++){
            int count=djikstra(n,i,adj,distanceThreshold);
            if(count <= ansCount){
                ansCount=count;
                ans=i;
            }
        }

        return ans;
    }
};




    --floyed warshall--own--accepted
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n,vector<int>(n,1e9));

        for(auto it:edges){
            dist[it[0]][it[1]]=it[2];
            dist[it[1]][it[0]]=it[2];
        }

        for(int helper=0;helper<n;helper++){
            for(int src=0;src<n;src++){
                for(int des=0;des<n;des++){
                    dist[src][des]=min(dist[src][des],dist[src][helper]+dist[helper][des]);
                }
            }
        }

        for(auto it:dist){
            for(auto it2:it){
                cout<<it2<<" ";
            }
            cout<<endl;
        }

        int ans=-1;
        int ansCount=INT_MAX;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(dist[i][j]<=distanceThreshold){
                    count++;
                }
            }
            if(count<=ansCount){
                ansCount=count;
                ans=i;
            }
        }

        return ans;
    }
};





class Solution {
public:

    ---LEETCODE 1334---TLE SOLU
    void dfs(int src,unordered_map<int,vector<pair<int,int>>>&adj,unordered_map<int,bool>&vis,int dist,int limit,unordered_set<int>&st){
        vis[src]=true;
        for(auto it:adj[src]){
            if(!vis[it.first] && dist+it.second<=limit){
                if(st.find(it.first)==st.end()){
                    st.insert(it.first);
                }
                dfs(it.first,adj,vis,dist+it.second,limit,st);
            }
        }
        vis[src]=false;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        int ans=-1;
        int ansCount=INT_MAX;
        for(int i=0;i<n;i++){
            unordered_map<int,bool>vis;
            unordered_set<int>st;
            dfs(i,adj,vis,0,distanceThreshold,st);
            // cout<<"For "<<i<<" Count is "<<st.size()<<endl;
            if(st.size()<=ansCount){
                ansCount=st.size();
                ans=i;
            }
        }

        return ans;
    }
};