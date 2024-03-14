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

    vector<vector<int>>visited(row,vector<int>(col,0));

    int rowStart=0;
    int rowEnd=row-1;

    int colStart=0;
    int colEnd=col-1;

    while(rowStart<=rowEnd && colStart<=colEnd){

        //ROW-START
        for(int c=0;c<col;c++){
            if(visited[rowStart][c]==0){
                cout<<v[rowStart][c]<<" ";
                visited[rowStart][c]=1;
            }
        }

        //COL-END
        for(int r=0;r<row;r++){
            if(visited[r][colEnd]==0){
                cout<<v[r][colEnd]<<" ";
                visited[r][colEnd]=1;
            }
        }

        //ROW-END
        for(int c=col-1;c>=0;c--){
            if(visited[rowEnd][c]==0){
                cout<<v[rowEnd][c]<<" ";
                visited[rowEnd][c]=1;
            }
        }

        //COL-START
        for(int r=row-1;r>=0;r--){
            if(visited[r][colStart]==0){
                cout<<v[r][colStart]<<" ";
                visited[r][colStart]=1;
            }
        }

        rowStart++;
        rowEnd--;
        colStart++;
        colEnd--;
    }

    
}