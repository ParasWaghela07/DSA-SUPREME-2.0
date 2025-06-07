#include<bits/stdc++.h>
using namespace std;

int getBinary(int n){
    int i=1;
    int ans=0;
    while(n>0){
        int bit=n%2;
        ans=bit*i + ans;
        i=i*10;
        n=n/2;
    }

    return ans;
}

int getBinary2(int n){
    int ans=0;
    int i=1;
    while(n>0){
        int bit=(n&1);
        ans=bit*i + ans;
        i=i*10;
        n=n>>1;
    }

    return ans;
}

int main(){
    int dnum=10;
    int bnum=getBinary2(dnum);

    cout<<"Decimal number :-"<<dnum<<endl;
    cout<<"Binary number :-"<<bnum<<endl;
}