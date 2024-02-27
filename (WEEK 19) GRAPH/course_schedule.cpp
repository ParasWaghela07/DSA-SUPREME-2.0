class Solution {
public:
    void toposortBfs(int n, unordered_map<int,list<int>>&adj,vector<int>&ans){
        unordered_map<int,int>indeg;
        for(auto i:adj){
            for(auto j:i.second){
                indeg[j]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int front=q.front();
            q.pop();

            ans.push_back(front);

            for(auto it:adj[front]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>>adj;
        for(auto i:prerequisites){
            int u=i[0];
            int v=i[1];

            adj[v].push_back(u);
        }

        vector<int>ans;
        toposortBfs(numCourses,adj,ans);
        if(numCourses!=ans.size()){
            return {};
        }
        else{
            return ans;
        }
    }
};