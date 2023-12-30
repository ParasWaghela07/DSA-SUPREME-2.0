#include<bits/stdc++.h>
using namespace std;

int PowerOfTwo(int n){
    if(n==1){
        return 2;
    }

    return 2*PowerOfTwo(n-1);
}

int main(){
    int num=3;
    cout<<PowerOfTwo(num)<<endl;
}