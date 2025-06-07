#include <bits/stdc++.h>
using namespace std;

//TIME : - O(MN) // SIZES OF STRINGS
//SPACE :- O(MN) // DP // TABLE

void printlcs(vector<vector<char>> &dir,int i,int j,string &b){
    if(dir[i][j]=='.') return;

    if(dir[i][j]=='*'){
        printlcs(dir,i-1,j-1,b);
        cout<<b[j-1];
    }
    else if(dir[i][j]=='<'){
        printlcs(dir,i,j-1,b);
    }
    else{
        printlcs(dir,i-1,j,b);
    }
}
int main()
{
    string a = "ABCDEF";
    string b = "ABCXYF";

    int n = a.size();
    int m = b.size();

    vector<vector<int>> match(n + 1, vector<int>(m + 1, 0));
    vector<vector<char>> dir(n + 1, vector<char>(m + 1, '.'));

    int it1 = 0;

    for (int i = 1; i < match.size(); i++)
    {
        int it2 = 0;
        for (int j = 1; j < match[0].size(); j++)
        {
            if(a[it1]==b[it2]){
                match[i][j]=match[i-1][j-1]+1;
                dir[i][j]='*';
            }
            else if(match[i-1][j]<match[i][j-1]){
                match[i][j]=match[i][j-1];
                dir[i][j]='<';
            }
            else{
                match[i][j]=match[i-1][j];
                dir[i][j]='^';
            }
            it2++;
        }
        it1++;
    }

    for(int i=0;i<match.size();i++){
        for(int j=0;j<match[0].size();j++){
            cout<<match[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    for(int i=0;i<match.size();i++){
        for(int j=0;j<match[0].size();j++){
            cout<<dir[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    cout<<"String a : "<<a<<endl;
    cout<<"String b : "<<b<<endl;

    cout<<endl;

    cout<<"LCS:-";
    printlcs(dir,dir.size()-1,dir[0].size()-1,b);
    cout<<endl<<"Size of lcs:- "<<match[match.size()-1][match[0].size()-1]<<endl;
}