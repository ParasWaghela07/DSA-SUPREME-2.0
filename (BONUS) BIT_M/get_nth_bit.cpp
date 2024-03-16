#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=10;
    int k=5;

    int mask=1<<k;
    
    if((n&mask)==0){
        cout<<0<<endl;
    }
    else{
        cout<<1<<endl;
    }
}