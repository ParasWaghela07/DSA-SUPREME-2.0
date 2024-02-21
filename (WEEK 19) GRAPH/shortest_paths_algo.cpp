#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
    unordered_map<int,list<pair<int,int>>>adj;

    void edge(int u,int v,int wt,int dir){
        if(dir==1){
            adj[u].push_back({v,wt});
        }
        else{
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
    }

    void print(){
        for(auto i:adj){
            cout<<i.first<<":"<<"{";
            for(auto j:i.second){
                cout<<"("<<j.first<<","<<j.second<<"),";
            }
            cout<<"}"<<endl;
        }
    }

    void shortestDistanceBfs(int src,int dest){ // UNDIRECTED GRAPH
        unordered_map<int,int>parent;
        parent[src]=-1;
        unordered_map<int,bool>visited;
        visited[src]=true;
        queue<int>q;
        q.push(src);

        while(!q.empty()){
            int front=q.front();
            q.pop();

            for(auto it:adj[front]){
                int nbrNode=it.first;
                //int nbrWt=it.second;
                if(!visited[nbrNode]){
                    visited[nbrNode]=true;
                    parent[nbrNode]=front;
                    q.push(nbrNode);
                }
            }

            while(dest!=-1){
                cout<<dest; // printed reversed
                dest=parent[dest];
            }
        }
    }

    void toposortDfs(int src,stack<int>&st,unordered_map<int,bool>&visited){
        visited[src]=true;

        for(auto it:adj[src]){
            int nbrNode=it.first;
            if(!visited[nbrNode]){
                toposortDfs(nbrNode,st,visited);
            }
        }

        st.push(src);
    }

    void shortestPathDfs(stack<int>&st,int n){
        vector<int>dist(n,INT_MAX);
        int src=st.top();
        dist[src]=0;

        while(!st.empty()){
            int src=st.top();
            st.pop();

            for(auto it:adj[src]){
                int nbrNode=it.first;
                int nbrWt=it.second; // src to nbr k bich ka dist

                if(dist[src]+nbrWt<dist[nbrNode]){
                    dist[nbrNode]=dist[src]+nbrWt;
                }
            }
        }

        cout << "Printing the distance array: " << endl;
		for(auto i: dist) {
			cout << i <<  " ";
		}
    }
};

int main(){
    graph g;
    g.edge(0,1,5,1);
    g.edge(0,2,2,1);
    g.edge(2,1,3,1);
    g.edge(1,3,3,1);
    g.edge(2,4,11,1);
    g.edge(4,3,14,1);

    int n=5;

    //g.print();
    stack<int>st;
    unordered_map<int,bool>visited;

    g.toposortDfs(0,st,visited);

    // while(!st.empty()){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }

    g.shortestPathDfs(st,n);

    

}