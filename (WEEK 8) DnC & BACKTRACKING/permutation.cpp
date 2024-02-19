#include<bits/stdc++.h>
using namespace std;

void prmt(string &s,int i){
    if(i>=s.size()){
        cout<<s<<endl;
        return;
    }

    for(int j=i;j<s.size();j++){
        swap(s[i],s[j]);
        prmt(s,i+1);
        swap(s[i],s[j]);
    }
}

int main(){
    string s="heet";
    int index=0;
    prmt(s,index);

}