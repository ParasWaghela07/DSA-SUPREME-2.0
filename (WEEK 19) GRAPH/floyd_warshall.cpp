#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    unordered_map<int,list<pair<int,int>>>adjList;

    void addegde(int u,int v,int wt,int dir){
        if(dir==1){
            adjList[u].push_back({v,wt});
        }
        else{
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }
    }

    void floyd_warshall(int n){
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }

        for(auto a:adjList){
            for(auto b:a.second){
                int u=a.first;
                int v=b.first;
                int wt=b.second;
                dist[u][v]=wt;
            }
        }

        for(int helper=0;helper<n;helper++){
            for(int src=0;src<n;src++){
                for(int des=0;des<n;des++){
                    dist[src][des]=min(dist[src][des],dist[src][helper]+dist[helper][des]);
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<dist[i][j]<<" ";
            }
            cout<<endl;
        }
    }

};

int main(){
    Graph g;
    g.addegde(0,1,3,1);
    g.addegde(1,0,2,1);
    g.addegde(0,3,5,1);
    g.addegde(1,3,4,1);
    g.addegde(3,2,2,1);
    g.addegde(2,1,1,1);

    g.floyd_warshall(4);

    

}

