
--- own---leetcode-2872
class Solution {
public:
    long long dfs(int src,unordered_set<int>&vis,int k,vector<int>&values,long long &res,unordered_map<int,vector<int>>&adj){

        vis.insert(src);
        long long sum=values[src];
        
        for(auto it:adj[src]){
            if(vis.find(it)!=vis.end()) continue;
            long long childsum=dfs(it,vis,k,values,res,adj);
            if(childsum%k==0) res++;
            else sum+=childsum;
        }

        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        unordered_map<int,vector<int>>adj;
        

        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        long long ans=1;
        unordered_set<int>vis;

        // for(int i=0;i<n;i++){
        //     long long temp=1;
        //     dfs(i,vis,k,values,temp,adj);
        //     ans=max(ans,temp);
        // }
        
            long long temp=1;
            dfs(0,vis,k,values,temp,adj);
            ans=max(ans,temp);
        

        return ans;
    }
};