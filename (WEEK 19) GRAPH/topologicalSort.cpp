#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
    unordered_map<int,list<int>>adj;

    void edge(int u,int v,int dir){
        if(dir==0){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        else{
            adj[u].push_back(v);
        }
    }

    void print(){
        for(auto i:adj){
            cout<<i.first<<":"<<"{";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<"}"<<endl;
        }
    }

    void toposortDfs(unordered_map<int,bool>&visited,int &src,stack<int>&st){
        visited[src]=true;

        for(auto it:adj[src]){
            if(!visited[it]){
                toposortDfs(visited,it,st);
            }
        }

        st.push(src);
    }

    void toposortBfs(int n,vector<int>&topoSort){
        //Kahn's ALGORITHM
        unordered_map<int,int>indegree;
        queue<int>q;

        for(auto i:adj){
            for(auto j:i.second){
                indegree[j]++;
            }
        }

        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int front=q.front();
            q.pop();
            topoSort.push_back(front);
            for(auto i:adj[front]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }


    }

    void shortestPathBfs(int src,int des,vector<int>&shortPath){
        unordered_map<int,bool>visited;
        unordered_map<int,int>parent;
        parent[src]=-1;

        queue<int>q;
        q.push(src);
        visited[src]=true;

        while(!q.empty()){
            int front=q.front();
            q.pop();

            for(auto i:adj[front]){
                if(!visited[i]){
                    visited[i]=true;
                    parent[i]=front;
                    q.push(i);
                }
            }

        }

        while(des!=-1){
            shortPath.push_back(des);
            des=parent[des];
        }

        reverse(shortPath.begin(),shortPath.end());

    }

};

int main(){
    graph g;

//for TOPO DFS
    // g.edge(0,1,1);
    // g.edge(1,2,1);
    // g.edge(2,3,1);
    // g.edge(3,4,1);
    // g.edge(3,5,1);
    // g.edge(4,6,1);
    // g.edge(5,6,1);
    // g.edge(6,7,1);

    // int n=8;



    // unordered_map<int,bool>visited;
    // stack<int>st;

    // for(int i=0;i<n;i++){
    //     if(!visited[i]){
    //         g.toposortDfs(visited,i,st);
    //     }
    // }

    // while(!st.empty()){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }

//FOR TOPO BFS 
//no cycle graph
    // g.edge(0,1,1);
    // g.edge(1,2,1);
    // g.edge(2,3,1);
    // g.edge(2,4,1);
    // g.edge(3,5,1);
    // g.edge(4,5,1);
    // g.edge(5,6,1);
    // g.edge(5,7,1);

//cycle graph
    // g.edge(0,1,1);
    // g.edge(1,2,1);
    // g.edge(2,3,1);
    // g.edge(4,3,1);
    // g.edge(3,5,1);
    // g.edge(6,4,1);
    // g.edge(5,6,1);
    // g.edge(6,7,1);

    // int n=8;

    // vector<int>topoSort;
    // g.toposortBfs(n,topoSort);
    // if(topoSort.size()==n){
    //     cout<<"No cycle"<<endl;
    // }
    // else{
    //     cout<<"Cycle present"<<endl;
    // }
    // for(auto i:topoSort){
    //     cout<<i<<" ";
    // }

//shortest path using bfs

// g.edge(0,5,0);
// g.edge(5,4,0);
// g.edge(4,3,0);
// g.edge(0,6,0);
// g.edge(6,3,0);
// g.edge(0,1,0);
// g.edge(1,2,0);
// g.edge(2,3,0);

g.edge(0,1,0);
g.edge(0,4,0);
g.edge(0,3,0);
g.edge(1,2,0);
g.edge(4,6,0);
g.edge(3,5,0);
g.edge(2,5,0);
g.edge(6,5,0);


int src=0;
int des=5;
vector<int>shortestPath;
g.shortestPathBfs(src,des,shortestPath);

for(auto it:shortestPath){
    cout<<it<<" ";
}

    
}