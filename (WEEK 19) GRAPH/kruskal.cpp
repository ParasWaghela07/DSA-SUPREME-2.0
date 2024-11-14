#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
    unordered_map<int,vector<pair<int,int>>>adjList;

    void addEdge(int u,int v,int wt,int dir){
        if(dir==1){
            adjList[u].push_back({v,wt});
        }
        else{
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }
    }

    int getParent(vector<int>&parent,int node){
        if(parent[node]==node) return node;

        return parent[node]=getParent(parent,parent[node]);
    }

    void unionSet(int u,int v,vector<int>&parent,vector<int>&rank){
        if(rank[u]<rank[v]){
            parent[u]=v;
            rank[v]++;
        }
        else{
            parent[v]=u;
            rank[u]++;
        }
    }

    int kruskalMst(int n){

        // JUST ENSURE WHILE PUSHING ALL EDGES , IF WE PUSH 1->2 AND DONT INSERT 2->1
        vector<vector<int>>edges;
        for(int i=0;i<n;i++){
            for(auto it:adjList[i]){
                edges.push_back({i,it.first,it.second});
            }
        }

        vector<int>parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        vector<int>rank(n,0);
        int ans=0;

        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];

            u=getParent(parent,u);
            v=getParent(parent,v);

            if(u!=v){
                ans+=wt;
                unionSet(u,v,parent,rank);
            }
        }
        return ans;
    }
};

int main(){
    graph g;
    // g.addEdge(1,0,5,0);
    // g.addEdge(1,2,2,0);
    // g.addEdge(2,0,3,0);
    // g.addEdge(2,3,1,0);
    // g.addEdge(2,4,4,0);
    // g.addEdge(3,4,3,0);

    

    g.addEdge(0,1,2,0);
    g.addEdge(0,3,6,0);
    g.addEdge(1,2,3,0);
    g.addEdge(1,3,8,0);
    g.addEdge(1,4,5,0);
    g.addEdge(2,4,7,0);
    g.addEdge(3,4,9,0);


    int n=5;

    int MinMstCost=g.kruskalMst(n);
    cout<<"MINIMUM COST : " <<MinMstCost<<endl;
}