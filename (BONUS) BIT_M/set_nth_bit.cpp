#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=10;
    int k=0;

    int mask=(1<<k);

    n=(n|mask);

    cout<<"Number after setting kth bit :- "<<n<<endl;
}