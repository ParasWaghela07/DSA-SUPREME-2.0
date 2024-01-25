#include<bits/stdc++.h>
using namespace std;
template<typename T>

class graph{
public:
unordered_map<T,vector<pair<T,int>>>adjList;

void addEdge(T u,T v,int wt,bool dir){
    if(dir==0){
        adjList[u].push_back({v,wt});
        adjList[v].push_back({u,wt});
    }
    else{
        adjList[u].push_back({v,wt});
    }
}

void printGraph(){
    for(auto it:adjList){
        cout<<it.first<<"->";
        for(auto it2:it.second){
            cout<<"{"<<it2.first<<","<<it2.second<<"} ";
        }
        cout<<endl;
    }
}

void bfs(T src,unordered_map<T,bool>&vis){
    queue<T>q;
    q.push(src);
    vis[src]=true;

    while(!q.empty()){
        T front=q.front();
        q.pop();

        cout<<front<<" ";
        auto temp=adjList[front];

        for(auto it:temp){
            if(!vis[it.first]){
                q.push(it.first);
                vis[it.first]=true;
            }
        }
    }
}

void dfs(T src,unordered_map<T,bool>&vis){
    vis[src]=true;
    cout<<src<<" ";
    auto temp=adjList[src];
    for(auto it:temp){
        if(!vis[it.first]){
            dfs(it.first,vis);
        }
    }
}
};

int main(){
    // graph<int> g;
    // g.addEdge(1,2,5,0);
    // g.addEdge(2,3,10,1);
    // g.addEdge(3,1,12,1);
    // g.addEdge(3,4,2,1);
    // g.addEdge(4,2,7,0);
    // g.printGraph();

    // cout<<endl;

    // graph<char> g2;
    // g2.addEdge('a','b',5,0);
    // g2.addEdge('b','c',10,1);
    // g2.addEdge('c','a',12,1);
    // g2.addEdge('c','d',2,1);
    // g2.addEdge('d','b',7,0);

    // g2.printGraph();





//  graph<char> g;
//  // cout << "HII" << endl;
//   g.addEdge('a','b',5,0);
// //   g.addEdge('a','c',10,0); //disconnct
//   g.addEdge('c','d',20,0);
//   g.addEdge('c','e',50,0);
//   g.addEdge('d','e',20,0);
//   g.addEdge('e','f',50,0);

//   unordered_map<char,bool>visited;
// //   g.bfs('a',visited); //WILL NOT WORK FOR DISCONNECTED GRAPH

// for(char c='a';c<='f';c++){

//     if(!visited[c])
//     g.bfs(c,visited);
    
// }

 graph<char> g;
 // cout << "HII" << endl;
  g.addEdge('a','b',5,0);
//   g.addEdge('a','c',10,0); //disconnect
  g.addEdge('c','d',20,0);
  g.addEdge('c','e',50,0);
  g.addEdge('d','e',20,0);
  g.addEdge('e','f',50,0);

  unordered_map<char,bool>visited;
//   g.bfs('a',visited); //WILL NOT WORK FOR DISCONNECTED GRAPH

for(char c='a';c<='f';c++){

    if(!visited[c])
    g.dfs(c,visited);
    
}
}