#include<bits/stdc++.h>
using namespace std;

void subq(string s,string op,int i){
    if(i>=s.size()){
        cout<<"->"<<op<<endl;
        return;
    }

    //exclude
    subq(s,op,i+1);

    //include
    op.push_back(s[i]);
    subq(s,op,i+1);

    

}

int main(){
    string str="abc";
    int index=0;
    string output="";
    subq(str,output,index);
}