#include<bits/stdc++.h>
using namespace std;
int getDecimal(int n){
    int i=0;
    int ans=0;

    while(n>0){
        int digit=n%10;
        ans += digit * pow(2,i);
        i++;

        n=n/10;

    }

    return ans;
}
int main(){
    int bnum=100000;
    int dnum=getDecimal(bnum);


    cout<<"Binary number :-"<<bnum<<endl;
    cout<<"Decimal number :-"<<dnum<<endl;
    
}