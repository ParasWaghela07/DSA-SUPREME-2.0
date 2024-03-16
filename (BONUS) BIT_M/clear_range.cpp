#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=1023;
    int i=8;
    int j=1;

    int a=(-1<<(i+1));
    int b=~(-1<<j);

    int mask=a|b;

    n=(n&mask);

    cout<<n<<endl;
}