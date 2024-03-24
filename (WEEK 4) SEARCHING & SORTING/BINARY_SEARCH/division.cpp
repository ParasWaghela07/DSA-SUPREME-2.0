#include<bits/stdc++.h>
using namespace std;

int main(){
    int nume=0;
    int deno=4;

    int s=0;
    int e=abs(nume);

    int ans=0;

    if(deno==0) {
        cout<<"Not defined"<<endl;
    }
    else{

        while(s<=e){
        int mid=s+(e-s)/2;

        if(mid*abs(deno)<=abs(nume)){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    if(nume<0 && deno>0 || nume>0 && deno<0){
        ans=ans*-1;
    }
    cout<<"Quientiont is :- "<<ans<<endl;

    }

}