#include<bits/stdc++.h>
using namespace std;

int sum(int n){
    if(n==1){
        return 1;
    }

    return n+sum(n-1);
}

int main(){
    int num=5;
    cout<<sum(num)<<endl;
}