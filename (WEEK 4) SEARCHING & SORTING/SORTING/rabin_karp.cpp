#include<bits/stdc++.h>
using namespace std;

//TIME :- O(M*(N-M+1))// BUT CAN BE BETTER THAN NAIVE DUE TO HASHING THEN MATCHING //BEST : O(N+M)
//SPACE :- O(1) // HASH VAR // SPURIOUS HITS


int main(){
    string t="ABGFDABTYACAB";
    string p="AB";

    int q=101;
    int d=10;

    int n=t.size();
    int m=p.size();

    int h=(int)pow(d,m-1)%q;
    

    int thash=0;
    int phash=0;

    for(int i=0;i<m;i++){
        thash=(thash*d)+t[i] % q;
        phash=(phash*d)+p[i] % q;
    }

    for(int i=0;i<n-m+1;i++){
        if(thash==phash){
            int j=0;
            while(j<m){
                if(t[i+j]!=p[j]){
                    break;
                }
                j++;
            }
            if(j==m){
                cout<<"FOUND AT : "<<i<<endl;
            }
        }

        if(i<m-n){
            thash=(d*(thash-h*t[i]+t[i+m]))%q;
        }
    }
    
}