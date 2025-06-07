#include<bits/stdc++.h>
using namespace std;

//TIME :- O(ELOGV) //GREEDY
//SPACE :- O(V+E) // MST

void printmst(vector<int>&parent,vector<vector<pair<int,int>>>&g){
    cout<<"Edge\t"<<"Weight"<<endl;
    for(int i=0;i<parent.size();i++){
        if(parent[i]==-1) continue;

        cout<<parent[i]<<" - "<<i<<"\t";
        for(auto it:g[i]){
            if(parent[i]==it.first){
                cout<<it.second<<endl;
                break;
            }
        }
    }
}

int getmin(vector<int>&dist,vector<bool>&mst){
    int val=INT_MAX;
    int index=-1;

    for(int i=0;i<dist.size();i++){
        if(dist[i]<val && !mst[i]){
            val=dist[i];
            index=i;
        }
    }

    return index;
}

int spanningtree(int &v,vector<vector<pair<int,int>>>&g){
    vector<int>dist(v,INT_MAX);
    vector<int>parent(v,-1);
    vector<bool>mst(v,false);

    dist[0]=0;

    while(true){
        int mini=getmin(dist,mst);

        if(mini==-1) break;

        mst[mini]=true;

        for(auto& it:g[mini]){
            int v=it.first;
            int wt=it.second;

            if(!mst[v] && wt<dist[v]){
                dist[v]=wt;
                parent[v]=mini;
            }
        }
    }

    int sum=0;

    for(int i=0;i<v;i++){
        if(parent[i]==-1) continue;

        for(auto it:g[i]){
            if(parent[i]==it.first){
                sum+=it.second;
            }
        }
    }
    printmst(parent,g);
    return sum;
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
int cost=spanningtree(v,g);

cout<<"MINIMUM COST:"<<cost<<endl;

}