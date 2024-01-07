#include<bits/stdc++.h>
using namespace std;


void lastOccurance(string&s,int target,int &lastIndex,int i){
    if(i>=s.size()){
        return;
    }
    if(s[i]==target){
        lastIndex=i;
    }
    i++;
    lastOccurance(s,target,lastIndex,i);
}
void lastOccuranceOptimized(string&s,int target,int &lastIndex,int i){
    if(i<0){
        return;
    }
    if(s[i]==target){
        lastIndex=i;
        return;
    }
    i--;
    lastOccuranceOptimized(s,target,lastIndex,i);
}
int main(){
    string s="abbcddfga";
    char target='a';
    int lastIndex=-1;
    // int i=0;
    int i=s.size()-1;
    lastOccuranceOptimized(s,target,lastIndex,i);
    cout<<lastIndex<<endl;
}