#include<bits/stdc++.h>
using namespace std;

void printsubarr(vector<int>&v,int index,vector<int>&temp){
    if(index>=v.size()){
        cout<<endl;
        return;
    }

    if(temp.size()>0){
            for(auto it:temp){
                cout<<it<<" ";
            }
        }

    for(int i=index;i<v.size();i++){
        temp.push_back(v[i]);
        printsubarr(v,index+1,temp);
        temp.pop_back();
    }
}

int main(){
    vector<int>v={1,2,3,4,5};
    vector<int>temp;
    printsubarr(v,0,temp);
}