#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=10;
    int k=1;

    int mask=~(1<<k);
    n=n&mask;

    cout<<"Number after clearing kth bit :- "<<n<<endl;
}