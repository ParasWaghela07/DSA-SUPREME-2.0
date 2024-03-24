#include<bits/stdc++.h>
using namespace std;

float getSqrt(int x){
    
    int s=1;
    int e=x;
    float ans=0;

    while(s<=e){
        long mid=s+(e-s)/2;

        if(mid*mid==x){
            return mid;
        }
        else if(mid*mid > x){
            e=mid-1;
        }
        else{
            s=mid+1;
            ans=mid;
        }
    }

    while(ans*ans<x){
        ans+=0.001;
    }

    return ans;

}

int main(){
    int n=2;
    float ans=getSqrt(n);

    cout<<"Sqrt of "<<n<<" : "<<ans<<endl;
}