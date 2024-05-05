#include<bits/stdc++.h>
using namespace std;

int slowexpo(int a,int b){
    int ans=1;
    while(b>0){
        ans=ans*a;
        b--;
    }

    return ans;
}

int fastexpo(int a,int b){
    int ans=1;
    
    while(b>0){
        if(b&1){
            ans=ans*a;
        }
        a=a*a;
        b=b>>1;
    }

    return ans;
}

int main(){
    int a=5;
    int b=4;

    int ans1=slowexpo(a,b);
    int ans2=fastexpo(a,b);

    cout<<"BY SLOW : "<<ans1<<endl;
    cout<<"BY FAST : "<<ans2<<endl;
}