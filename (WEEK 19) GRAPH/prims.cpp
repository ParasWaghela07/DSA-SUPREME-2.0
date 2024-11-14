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

    int getMin(vector<int>&key,vector<bool>&vis){
        int mini=INT_MAX;
        int element=-1;

        for(int i=0;i<key.size();i++){
            if(!vis[i] && key[i]<mini){
                mini=key[i];
                element=i;
            }
        }

        return element;
    }

    int primsMst(int n){
        vector<int>key(n,INT_MAX);
        vector<bool>visited(n,false);
        vector<int>parent(n,-1);

        key[0]=0;

        while(1){
            int mini=getMin(key,visited);
            if(mini==-1) break;

            visited[mini]=true;

            for(auto it:adjList[mini]){
                int v=it.first;
                int wt=it.second;

                if(!visited[v] && wt < key[v]){
                    key[v]=wt;
                    parent[v]=mini;
                }

            }

        }

        int sum=0;
        for(int i=0;i<n;i++){
            if(parent[i]==-1) continue;

            for(auto it:adjList[i]){
                if(it.first==parent[i]){
                    sum+=it.second;

                    cout<<i<<" - "<<it.first<<" : "<<it.second<<endl;
                }
            }
        }

        return sum;
    }
};

int main(){
    graph g;
    // g.addEdge(1,0,5,0);
    // g.addEdge(1,2,2,0);
    // g.addEdge(2,0,3,0);
    // g.addEdge(2,3,1,0);
    // g.addEdge(2,4,4,0);
    // g.addEdge(3,4,5,0);

    g.addEdge(0,1,2,0);
    g.addEdge(0,3,6,0);
    g.addEdge(1,2,3,0);
    g.addEdge(1,3,8,0);
    g.addEdge(1,4,5,0);
    g.addEdge(2,4,7,0);
    g.addEdge(3,4,9,0);


    int n=5;

    int MinMstCost=g.primsMst(n);
    cout<<"MINIMUM COST : " <<MinMstCost<<endl;
}