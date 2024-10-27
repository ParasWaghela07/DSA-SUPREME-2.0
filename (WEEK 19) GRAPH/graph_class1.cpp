#include<bits/stdc++.h>
using namespace std;

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

    void bfs(T src){

        unordered_map<T,bool>visited;

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
    // graph<int>g;

    // g.insert(1,2,5,1);
    // g.insert(1,3,5,1);
    // g.insert(2,3,5,1);
    // g.insert(2,3,10,1);
    // g.insert(3,4,2,1);
    // g.insert(4,5,1,1);
    // g.insert(5,1,5,1);

    // graph<char>g;

    g.insert('a','b',5,1);
    g.insert('a','c',5,1);
    g.insert('b','c',5,1);
    g.insert('b','c',10,1);
    g.insert('c','d',2,1);
    g.insert('d','e',1,1);
    g.insert('e','a',5,1);

    g.printAdjList();




}