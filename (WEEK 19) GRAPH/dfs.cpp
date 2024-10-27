#include<bits/stdc++.h>
using namespace std;

//         a
//        / \
//      b --- c
//           / \
//          d   e
//               \
//                 f

template<typename T>
class graph{
    public:
    unordered_map<T,vector<pair<T,int>>>adjList;

    void insert(T u,T v,int wt,int dir){

        if(dir==1)
        adjList[u].push_back({v,wt});
        else{
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }
    }

    void printAdjList(){
        for(auto it:adjList){
            cout<<it.first<<" : "<<"[ ";
            for(auto it2:it.second){
                cout<<"{"<<it2.first<<","<<it2.second<<"} , ";
            }
            cout<<"]"<<endl;
        }
    }

    void dfs(T src,unordered_map<T,bool>&visited){
        
        cout<<src<<" ";
        visited[src]=true;

        for(auto it:adjList[src]){
            if(!visited[it.first]){
                dfs(it.first,visited);
            }
        }
    }

};

int main(){

    // graph<char>g;
    // g.insert('a','b',5,0);
    // g.insert('a','c',5,0);
    // g.insert('b','c',5,0);
    // g.insert('c','d',5,0);
    // g.insert('c','e',5,0);
    // g.insert('e','f',5,0);

    // // g.printAdjList();

    // unordered_map<char,bool>visited;

    // g.dfs('a',visited);


    //DISCONNECTED COMPONENTS
    graph<char>g;
    g.insert('a','b',5,0);
    g.insert('b','c',5,0);

    g.insert('d','e',5,0);

    g.insert('d','e',5,0);

    g.insert('f','f',5,0);
    unordered_map<char,bool>visited;

    for(char node='a';node<='f';node++){
        if(!visited[node]) g.dfs(node,visited);
    }
}