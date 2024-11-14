#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    unordered_map<char,list<pair<char,int>>>adjList;

    void addegde(char u,char v,int wt,int dir){
        if(dir==1){
            adjList[u].push_back({v,wt});
        }
        else{
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }
    }


    void bellmonford(int n,char src){
    vector<int>dist(n,INT_MAX);
    dist[src-'A']=0;

    for(int i=0;i<n-1;i++){
        for(auto a:adjList){
            for(auto b:a.second){
                char u=a.first;
                char v=b.first;
                char wt=b.second;

                if(dist[u-'A'] != INT_MAX && dist[u-'A']+wt < dist[v-'A']){
                    dist[v-'A']=dist[u-'A']+wt;
                }
            }
        }
    }

    bool anyUpdate=false;
    for(auto a:adjList){
            for(auto b:a.second){
                char u=a.first;
                char v=b.first;
                char wt=b.second;

                if(dist[u-'A'] != INT_MAX && dist[u-'A']+wt < dist[v-'A']){
                    anyUpdate=true;
                    break;
                }
            }
        }

        if(anyUpdate==true){
            cout<<"Negative cycle present"<<endl;
        }
        else{
            cout<<"Negative cycle not present"<<endl;
            for(auto it:dist){
                cout<<it<<",";
            }
        }

}
};

int main(){
    Graph g;
        //TRY ADDING NODES IN BETWEEN WHICH IS NOT ENCOUNTERED YET SO DUE TO ITS INT_MAX IT WILL BE SKIPPED AND PATH THRU THAT NODE WILL BE UNCHECKED AND I WILL LEAD TO MORE RELAXATION STEPS
        
    // g.addegde('A','B',5,1);
    // g.addegde('B','D',2,1);
    // g.addegde('B','C',1,1);
    // g.addegde('E','D',-1,1);
    // g.addegde('D','F',2,1);
    // g.addegde('F','E',-3,1);
    // g.addegde('C','E',1,1);

    // g.addegde('A','B',1,1);
    // g.addegde('A','D',1,1);
    // g.addegde('B','C',2,1);
    // g.addegde('B','D',1,1);
    // g.addegde('D','A',4,1);
    // g.addegde('D','C',3,1);

    // g.addegde('A', 'B', 4, 1);
    // g.addegde('A', 'C', 5, 1);
    // g.addegde('B', 'C', -2, 1);
    // g.addegde('B', 'D', 6, 1);
    // g.addegde('C', 'D', 3, 1);
    // g.addegde('D', 'E', 2, 1);
    // g.addegde('E', 'B', -8, 1);





    g.bellmonford(5,'A');

}

