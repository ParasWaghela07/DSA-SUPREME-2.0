#include<bits/stdc++.h>
using namespace std;

//TIME : - O(N!) // BACKTRACKING
//SPACE :- O(N^2) //  BOARD // BRUTE FORCE

void printqueen(auto &b){
    for(int i=0;i<b.size();i++){
        for(int j=0;j<b[0].size();j++){
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool check(auto &b,int x,int y){
    int row=b.size();
    int col=b[0].size();
    
    int i=x;
    int j=y;

    while(i>=0){
        if(b[i][j]=='Q') return false;
        i--;
    }

    i=x;

    while(i>=0 && j>=0){
        if(b[i][j]=='Q') return false;
        i--;
        j--;
    }

    i=x;
    j=y;

    while(i>=0 && j<col){
        if(b[i][j]=='Q') return false;
        i--;
        j++;
    }

    return true;

}
void nqueen(int i,int q,auto &b,int &count){
    if(q==0){
        // printqueen(b);
        count++;
        cout<<endl;
        return;
    }

    for(int j=0;j<b[0].size();j++){
        if(check(b,i,j)){
            b[i][j]='Q';
            nqueen(i+1,q-1,b,count);
            b[i][j]='_';
        }
    }
}

int main(){
    int n=6;
    int count=0;
    vector<vector<char>>b(n,vector<char>(n,'_'));

    int queen=n;

    nqueen(0,queen,b,count);

    cout<<"Total ways :- "<<count<<endl;



}