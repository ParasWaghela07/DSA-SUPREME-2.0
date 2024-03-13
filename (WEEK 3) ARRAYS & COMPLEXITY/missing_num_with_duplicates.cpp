#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>v={1,2,5,3,3};

    int index=0;
    while(index<v.size()){
        if(v[index]!=v[v[index]-1]){
            swap(v[index],v[v[index]-1]);
        }
        else{
            index++;
        }
    }

    // for(int i=0;i<v.size();i++){
    //     cout<<v[i]<<" ";
    // }

    // cout<<endl;

    for(int i=0;i<v.size();i++){
        if(v[i]-i!=1){
            cout<<"Missing num:- "<<i+1<<endl;
        }
    }
///////////////////////////////////////////////////////////////// MARK VISITED METHOD
    for(int i=0;i<v.size();i++){ 
        int index=abs(v[i])-1; 
        if(v[index]>0){ 
            v[index]*=-1; 
        } 
    } 
    for(int i=0;i<v.size();i++){ 
        if(v[i]>0){ 
            cout<<"Missing num:- "<<i+1<<endl; 
            break; 
        } 
    } 

    
}


