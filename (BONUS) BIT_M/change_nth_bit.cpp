#include<bits/stdc++.h>
using namespace std;

void clear_nth_bit(int &n,int &k){
    int mask=~(1<<k);
    n=n&mask;
}

int main(){
    int n=10;
    int k=2;
    int target=1;

    clear_nth_bit(n,k);

    int mask=(target<<k);

    n=n|mask;

    cout<<n<<endl;
}