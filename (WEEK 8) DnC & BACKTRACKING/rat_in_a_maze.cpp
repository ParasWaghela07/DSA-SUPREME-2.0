#include<bits/stdc++.h>
using namespace std;

void printpaths(vector<vector<int>>&maze,int &row,int &col,int i,int j,string&op){
    if(i>=row || i<0 || j>=col || j<0 || maze[i][j]==0){
        return;
    }
    if(i==row-1 && j==col-1){
        cout<<op<<endl;
        return;
    }
    
    maze[i][j]=0;

    op.push_back('D');
    printpaths(maze,row,col,i+1,j,op);
    op.pop_back();

    op.push_back('U');
    printpaths(maze,row,col,i-1,j,op);
    op.pop_back();

    op.push_back('R');
    printpaths(maze,row,col,i,j+1,op);
    op.pop_back();

    op.push_back('L');
    printpaths(maze,row,col,i,j-1,op);
    op.pop_back();

    maze[i][j]=1;

}
int main(){
    vector<vector<int>>maze={
        {1,0,0,0},
        {1,1,0,0},
        {1,1,1,0},
        {1,1,1,1}
    };
    int row=maze.size();
    int col=maze[0].size();

    string op="";
    printpaths(maze,row,col,0,0,op);

}