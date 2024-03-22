#include<bits/stdc++.h>
using namespace std;


void printMST(vector<int>&parent, vector<vector<pair<int, int>>>& adj)
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < parent.size(); i++){
        cout << parent[i] << " - " << i << " \t";
             for(auto it:adj[i]){
                if(it.first==parent[i]){
                    cout<<it.second<< " \n";
                    break;
                }
             }
    }
}

int minVal(vector<int>& key, vector<bool>& mst) {
    int mini = INT_MAX;
    int index = -1;

    for(int i = 0; i < key.size(); i++) {
        if(!mst[i] && key[i] < mini) {
            mini = key[i];
            index = i;
        }
    }

    return index;
}

int spanningTree(int V, vector<vector<pair<int, int>>>& adj) {
    vector<int> key(V, INT_MAX);
    vector<bool> mst(V, false);
    vector<int> parent(V, -1);

    key[0] = 0;

    while(true) {
        int u = minVal(key, mst);

        if(u == -1) break;

        mst[u] = true;

        for(auto& it : adj[u]) {
            int v = it.first;
            int w = it.second;

            if(!mst[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
            }
        }
    }
    int sum = 0;
    for(int u = 0; u < V; u++) {
        if(parent[u] == -1) continue;

        for(auto& it : adj[u]) {
            if(parent[u] == it.first) {
                sum += it.second;
            }
        }
    }
    printMST(parent, adj);
    return sum;
}

int main() {
    vector<vector<pair<int, int>>> g = {
        {{1, 2}, {3, 6}},
        {{0, 2}, {2, 3}, {3, 8}, {4, 5}},
        {{1, 3}, {4, 7}},
        {{0, 6}, {1, 8}, {4, 9}},
        {{1, 5}, {2, 7}, {3, 9}}
    };

    int V = g.size();
    int ans = spanningTree(V, g);

    cout << "MINIMUM COST :-" << ans << endl;
    return 0;
}
