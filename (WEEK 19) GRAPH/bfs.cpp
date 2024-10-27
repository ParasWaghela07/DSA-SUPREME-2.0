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

    void bfs(T src,unordered_map<T,bool>&visited){

        queue<T>q;
        q.push(src);
        visited[src]=true;

        while(!q.empty()){
            T front=q.front();
            q.pop();

            cout<<front<<" ";

            for(auto it:adjList[front]){
                if(!visited[it.first]){
                    visited[it.first]=true;
                    q.push(it.first);
                }
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

    // g.printAdjList();

    // g.bfs('a');


    //DISCONNECTED COMPONENTS
    graph<char>g;
    g.insert('a','b',5,0);
    g.insert('b','c',5,0);

    g.insert('d','e',5,0);

    g.insert('d','e',5,0);

    g.insert('f','f',5,0);

    // g.bfs('a');

    unordered_map<char,bool>visited;

    for(char node='a';node<='f';node++){
        if(!visited[node]){
            g.bfs(node,visited);
        }
    }


}