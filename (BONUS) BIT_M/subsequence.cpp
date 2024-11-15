#include<iostream>
using namespace std;

int main(){
    string s="abc";

    for(int num=0;num<(1<<s.size());num++){
        string temp="";
        for(int i=0;i<s.size();i++){
            int mask=(1<<i);
            if((num&mask)==0){
                continue;
            }
            else{
                temp+=s[i];
            }
        }
        cout<<"-> "<<temp<<endl;
    }
}