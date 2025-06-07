#include<bits/stdc++.h>
using namespace std;

//TIME :- O(NLOGN) // GREEDY //sorting
//SPACE :- O(N) // JOBS OBJECTS

int check(auto &ans,int d){
    for(int i=0;i<ans.size();i++){
        if(ans[i]==-1) return i;
    }

    return -1;
}

int main(){
    vector<int>p={100,10,15,27};
    vector<int>d={2,1,2,1};

    for(int i=0;i<p.size()-1;i++){
        for(int j=0;j<p.size()-i-1;j++){
            if(p[j]<p[j+1]){
                swap(p[j],p[j+1]);
                swap(d[j],d[j+1]);
            }
        }
    }
    int n=0;
    for(int i=0;i<d.size();i++){
        n=max(n,d[i]);
    }

    vector<int>ans(n,-1);
    for(int i=0;i<p.size();i++){
        int index=check(ans,d[i]);
        if(index!=-1){
            ans[index]=p[i];
        }
    }
    cout<<"Profits are : "<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }

}