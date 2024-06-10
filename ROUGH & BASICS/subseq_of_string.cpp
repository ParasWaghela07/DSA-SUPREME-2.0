#include<bits/stdc++.h>
using namespace std;

void subseq(string &s,int index,string &curr){
    if(index>=s.size()){
        cout<<"Subseq:-"<<curr<<endl;
        return;
    }

    char ch=s[index];
    curr.push_back(ch);
    subseq(s,index+1,curr);
    curr.pop_back();

    subseq(s,index+1,curr);
}

int main(){
    string s="abc";
    string curr;
    subseq(s,0,curr);
}