#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>>v={
        {1,4,7,8},
        {2,4,6,9},
        {1,3,2,7},
        {1,5,6,9}
    };

    int row=v.size();
    int col=v[0].size();

    int flow=1;

    for(int j=0;j<col;j++){
        if(flow==1){
            for(int i=0;i<row;i++){
                cout<<v[i][j]<<" ";
            }
            flow=0;
        }
        else{
            for(int i=row-1;i>=0;i--){
                cout<<v[i][j]<<" ";
            }
            flow=1;
        }
    }

}