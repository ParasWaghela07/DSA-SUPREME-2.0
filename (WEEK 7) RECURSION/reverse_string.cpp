#include<bits/stdc++.h>
using namespace std;

// void revString(string &s){
//     if(s.size()==0){
//         return;
//     }
//     char temp=s[0];
//     s=s.substr(1);
//     revString(s);
//     s.push_back(temp);
// }

void reverseBytwoPointers(string &str , int s, int e){
    if(s>e){
        return;
    }
    swap(str[s],str[e]);
    reverseBytwoPointers(str,s+1,e-1);
}

int main(){
    string s="hot";
    reverseBytwoPointers(s,0,s.size()-1);
    // revString(s);
    cout<<s<<endl;
}