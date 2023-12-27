#include<bits/stdc++.h>
using namespace std;

void solveForMediun(double&median,priority_queue<int> &maxi,priority_queue<int,vector<int>,greater<int>> &mini,int element){
    
    if(maxi.size()==mini.size()){
        if(element<median){
            maxi.push(element);
            median=maxi.top();
            
        }
        else{
            mini.push(element);
            median=mini.top();
        }
         
    }
    else if(maxi.size()==mini.size()+1){
         if(element>median){
            mini.push(element);
             median=(maxi.top()+mini.top())/2.0;
         }
         else{
            int temp=maxi.top();maxi.pop();
            mini.push(temp);
            maxi.push(element);

            median=(maxi.top()+mini.top())/2.0;
         }
    }
    else if(mini.size()==maxi.size()+1){
        if(element<median){
            maxi.push(element);
            median=(maxi.top()+mini.top())/2.0;
        }
        else{
            int temp=mini.top(); mini.pop();
            maxi.push(temp);
            mini.push(element);

            median=(maxi.top()+mini.top())/2.0;
        }
    }
}

int main(){
    int arr[]={12,10,8,4,2,3,15};
    int  n=7;

    priority_queue<int>maxi;
    priority_queue<int,vector<int>,greater<int>>mini;
    double median=0;

    for(int i=0;i<n;i++){
        int element=arr[i];
        solveForMediun(median,maxi,mini,element);
        cout<<"Median found : "<<median<<endl;
    }
}