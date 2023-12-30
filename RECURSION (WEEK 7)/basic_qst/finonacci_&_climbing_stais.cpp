#include<bits/stdc++.h>
using namespace std;
//recursive app
int fibonacci(int n) // exactly same code for climbing stairs problem
{
    if(n==0) return 0;
    if(n==1) return 1;

    return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    int nth_term=8;
    // cout<<fibonacci(num)<<endl;


    //iterative app
    int i=0;
    int j=1;
    if(nth_term==1){
        cout<<i<<endl;
    }
    else if(nth_term==2){
        cout<<i<<" "<<j<<endl;
    }
    else{
        cout<<i<<" "<<j<<" ";
        nth_term=nth_term-2;
        while(nth_term--){
            int k=i+j;
            cout<<k<<" ";
            i=j;
            j=k;
    }
    }
}