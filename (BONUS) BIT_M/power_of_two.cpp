#include<bits/stdc++.h>
using namespace std;

void slow_method(int n){
    int count=0;
    while(n!=0){
        if(n&1){
            count++;
        }
        n=n>>1;
    }

    if(count==1){
        cout<<"TRUE"<<endl;
    }
    else{
        cout<<"FALSE"<<endl;
    }
}

void fast_method(int n){
    if( (n&(n-1)) == 0 ){
        cout<<"TRUE"<<endl;
    }
    else{
        cout<<"FALSE"<<endl;
    }
}

int main(){
    int n=2048;
    slow_method(n);
    
    fast_method(n);
}