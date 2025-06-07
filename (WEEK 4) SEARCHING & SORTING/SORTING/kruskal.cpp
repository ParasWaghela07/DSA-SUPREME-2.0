#include<bits/stdc++.h>
using namespace std;

//TIME :- O(ELOGE)//SORTING EDGES
//SPACE :- O(V+E) // GREEDY //MST

static bool mycomp(vector<int>&a,vector<int> &b){
        return a[2]<b[2];
    }
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int findparent(vector<int>&parent,int node){
	    if(parent[node]==node) {
	        return node;
	    }
	    return parent[node]=findparent(parent,parent[node]);
	}
	
	void printmst(vector<int>&parent,vector<vector<pair<int,int>>>&g){
    cout<<"Edge\t"<<"Weight"<<endl;
    for(int i=0;i<parent.size();i++){
        if(parent[i]==i) continue;

        cout<<parent[i]<<" - "<<i<<"\t";
        for(auto it:g[i]){
            if(parent[i]==it.first){
                cout<<it.second<<endl;
                break;
            }
        }
    }
}

	void unionset(int u,int v,vector<int>&parent,vector<int>&rank){
	    u=findparent(parent,u);
	    v=findparent(parent,v);
	    
	    if(rank[u]>rank[v]){
	        parent[v]=u;
	        rank[u]++;
	    }
	    else{
	        parent[u]=v;
	        rank[v]++;
	    }
	}
	
	
    int spanningTree(int V, vector<vector<pair<int,int>>>&adj)
    {
        vector<int>parent(V);
        vector<int>rank(V,0);
        int ans=0;
        
        for(int i=0;i<V;i++){
            parent[i]=i;
        }
        
        vector<vector<int>>edges;
        for(int u=0;u<V;u++){
            for(auto it:adj[u]){
                edges.push_back({u,it.first,it.second});
            }
        }
        
        sort(edges.begin(),edges.end(),mycomp);
        
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            
            u=findparent(parent,u);
	        v=findparent(parent,v);
	        
	        if(u!=v){
	            unionset(u,v,parent,rank);
	            ans+=w;
	        }
        }
        printmst(parent,adj);
        return ans;
    }

int main(){
     vector<vector<pair<int,int>>>g={
        {{1,2},{3,6}},
        {{0,2},{2,3},{3,8},{4,5}},
        {{1,3},{4,7}},
        {{0,6},{1,8}},
        {{1,5},{2,7},{3,9}}
};

int v=g.size();
int cost=spanningTree(v,g);

cout<<"MINIMUM COST:"<<cost<<endl;
}
