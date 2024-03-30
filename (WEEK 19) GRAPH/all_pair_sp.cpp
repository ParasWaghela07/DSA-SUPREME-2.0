#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> g = {
        {0, 7, 2, 9, 1000},
        {1000, 0, 1000, 1, 3},
        {1000, 1000, 0, 3, 1000},
        {1000, 1000, 1000, 0, 1},
        {1000, 1000, 1000, 1000, 0}};

    vector<vector<int>> dist(g.size(), vector<int>(g[0].size(), 1000000));

    for (int i = 0; i < g.size(); i++)
    {
        for (int j = 0; j < g[0].size(); j++)
        {
            dist[i][j] = g[i][j];
        }
    }

    for(int i=0;i<g.size();i++){
        for(int j=0;j<g[0].size();j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    for (int helper = 0; helper < g.size(); helper++)
    {
        for (int i = 0; i < g.size(); i++)
        {
            for (int j = 0; j < g[0].size(); j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][helper] + dist[helper][j]);
            }
        }
    }

    for (int i = 0; i < g.size(); i++)
    {
        for (int j = 0; j < g[0].size(); j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}