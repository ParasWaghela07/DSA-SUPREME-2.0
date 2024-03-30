#include <bits/stdc++.h>
using namespace std;




void printLCS(vector<vector<char>>&dir,int i,int j,string &b){
   if(dir[i][j]=='.'){
       return;
   }
  
   if(dir[i][j]=='*'){
      
       printLCS(dir,i-1,j-1,b);
      
       cout<<b[j-1];
      
   }
   if(dir[i][j]=='<'){
       printLCS(dir,i,j-1,b);
   }
   if(dir[i][j]=='^'){
       printLCS(dir,i-1,j,b);
   }
}
int main() {
  
   string a="ABCDEF";
   string b="ABCXYF";
  
   int n=a.size();
   int m=b.size();
  
   int it1=0;
  
   vector<vector<int>>c(n+1,vector<int>(m+1,0));
   vector<vector<char>>dir(n+1,vector<char>(m+1,'.'));


   for(int i=1;i<n+1;i++){
       int it2=0;
       for(int j=1;j<m+1;j++){
           if(a[it1]==b[it2]){
               c[i][j]=c[i-1][j-1]+1;
               dir[i][j]='*';
           }
           else if(c[i][j-1]>c[i-1][j]){
               c[i][j]=c[i][j-1];
               dir[i][j]='<';
           }
           else{
               c[i][j]=c[i-1][j];
               dir[i][j]='^';
           }
           it2++;
       }
       it1++;
   }
  
   for(int i=0;i<n+1;i++){
       for(int j=0;j<m+1;j++){
           cout<<c[i][j]<<" ";
       }
       cout<<endl;
   }
   cout<<endl;
   for(int i=0;i<n+1;i++){
       for(int j=0;j<m+1;j++){
           cout<<dir[i][j]<<" ";
       }
       cout<<endl;
   }
   cout<<endl;
   cout<<"String a: "<<a<<endl;
   cout<<"String b: "<<b<<endl;
   cout<<endl<<"Longest common subsequence :- ";
   printLCS(dir,n,m,b);


   cout<<endl<<"Size :- "<<c[n][m]<<endl;


   return 0;
}
