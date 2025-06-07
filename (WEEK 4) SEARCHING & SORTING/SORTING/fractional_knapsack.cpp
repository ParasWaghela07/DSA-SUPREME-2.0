#include<bits/stdc++.h>
using namespace std;

//TIME :- O(NLOGN) //GREEDY //SORTING
//SPACE :- O(N)

int main(){
    vector<int>profit={30,20,10};
    vector<int>weight={20,10,2};
    int n=profit.size();
    int m=10;

    vector<float>ratio(n);
    for(int i=0;i<n;i++){
        ratio[i]=profit[i]/(float)weight[i];
    }

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(ratio[j]<ratio[j+1]){
                swap(ratio[j],ratio[j+1]);
                swap(profit[j],profit[j+1]);
                swap(weight[j],weight[j+1]);
            }
        }
    }

    float p=0;
    int wt=0;

    for(int i=0;i<n;i++){
        if(weight[i]+wt<=m){
            p+=profit[i];
            wt+=weight[i];
        }
        else{
            // cout<<profit[i]<<" <-Nai le paa rhe"<<endl;
            int x=m-wt;
            float to_add=(x*profit[i])/(float)weight[i];
            p+=to_add;
            break;
        }
    }

    cout<<"PROFIT:"<<p<<endl;

}