class Solution {
public:
    int getParent(vector<int>&parent,int node){
        if(parent[node]==node) return node;

        return parent[node]=getParent(parent,parent[node]);
    }

    void unionSet(int u,int v,vector<int>&parent,vector<int>&rank){
        u=getParent(parent,u);
        v=getParent(parent,v);
        if(rank[u]<rank[v]){
            parent[u]=v;
            rank[v]++;
        }
        else{
            parent[v]=u;
            rank[u]++;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        vector<int>parent(n);
        vector<int>rank(n,0);

        for(int i=0;i<n;i++) parent[i]=i;

        unordered_map<string,int>mp;
        for(int i=0;i<accounts.size();i++){
            auto currAc=accounts[i];
            for(int j=1;j<currAc.size();j++){
                if(mp.find(currAc[j])==mp.end()){
                    mp[currAc[j]]=i;
                }
                else{
                    unionSet(i,mp[currAc[j]],parent,rank);
                }
            }
        }


        unordered_map<int,set<string>>preAns;
        for(auto it:mp){
            string mail=it.first;
            int accNo=it.second;

            int actaccNo=getParent(parent,accNo);

            preAns[actaccNo].insert(mail);
        }

        vector<vector<string>>ans;
        for(auto it:preAns){
            vector<string>temp;
            temp.push_back(accounts[it.first][0]);

            for(auto it2:it.second)temp.push_back(it2);
            ans.push_back(temp);
        }

        return ans;
    }
};