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

    cout<<"Set bits by slow method:- "<<count<<endl;
}

void fast_method(int n){
    int count=0;

    while(n!=0){
        count++;
        n=(n&(n-1));
    }

    cout<<"Set bits by fast method:- "<<count<<endl;
}

int main(){
    int n=6;

    slow_method(n);

    fast_method(n);


}