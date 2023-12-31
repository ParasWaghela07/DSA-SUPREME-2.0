#include<bits/stdc++.h>
using namespace std;

class info{
    public:
int data;
int row;
int col;

info(int val,int row,int column){
    this->data=val;
    this->row=row;
    this->col=column;
}
};

class compare{
public:
bool operator()(info* a,info* b){
    return a->data > b->data;
}
};
void mergeKsortedArrays(int arr[][4],int col,int row,vector<int>&ans){
    priority_queue<info*,vector<info*>,compare>pq;

    for(int i=0;i<row;i++){
        info* temp=new info(arr[i][0],i,0);
        pq.push(temp);
    }

    while(!pq.empty()){
        info* topElement=pq.top(); pq.pop();
        int topValue=topElement->data;
        int topRow=topElement->row;
        int topCol=topElement->col;

        ans.push_back(topValue);
        cout<<topValue<<endl;

        if(topCol+1 < col){
            info* temp=new info(arr[topRow][topCol+1],topRow,topCol+1);
            pq.push(temp);
        }

    }
}

int main(){
    int arr[3][4]={
        {1,4,8,11},
        {2,3,6,10},
        {5,7,12,14}
    };
    int n=4; // total elements in array
    int k=3; // number of arrays
    vector<int>ans;
    mergeKsortedArrays(arr,n,k,ans);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}