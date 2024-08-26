#include<bits/stdc++.h>
using namespace std;


//SOLUTION 1
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

//SOLUTION 2 // ONLY USEFUL FOR SQUARE MATRIX

void helper(int arr[][4],int col,int row,vector<int>&ans){
    priority_queue<int,vector<int>,greater<int>>pq;

        for(int i=0;i<row;i++){
            pq.push(arr[i][0]);
        }

        int top=pq.top();
        pq.pop();

        ans.push_back(top);

        for(int i=1;i<col;i++){
            for(int j=0;j<row;j++){
                pq.push(arr[j][i]);

                        int top=pq.top();
                        pq.pop();

                        ans.push_back(top);
            }
        }
}
//SOLUTION 3
class Solution {
public:
    class info{
        public:
        int data;
        int row;
        int col;

        info(int data,int row,int col){
            this->data=data;
            this->row=row;
            this->col=col;
        }
    };

    class compare{
        public:
        bool operator()(const info&a,const info&b){
            return a.data>b.data;
        }
    };


    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<info,vector<info>,compare>pq;

        for(int i=0;i<nums.size();i++){
            info temp=info(nums[i][0],i,0);
            pq.push(temp);
        }

        vector<pair<int,int>>merged;

        while(!pq.empty()){
            info top=pq.top();
            pq.pop();

            int val=top.data;
            int row=top.row;
            int col=top.col;

            merged.push_back({val,row});

            if(col+1<nums[row].size()){
                info temp=info(nums[row][col+1],row,col+1);
                pq.push(temp);
            }
        }

        for(auto it:merged){
            cout<<it.first<<","<<it.second<<" ";
        }
        unordered_map<int, int> mp;
        int i = 0;
        int j = 0;

        int lhs = 0, rhs = 1e9;

        int count = 0;
        int k = nums.size();

        while (j < merged.size()) {

            int listNum = merged[j].second;

            if (mp.find(listNum) == mp.end()) {
                count++;
            }
            mp[listNum]++;

            while (count == k) {
                cout<<"["<<merged[i].first<<","<<merged[j].first<<"]"<<endl;

                if (merged[j].first - merged[i].first < rhs - lhs) {
                    rhs = merged[j].first;
                    lhs = merged[i].first;
                }

                int value = merged[i].second;
                mp[value]--;
                if (mp[value] == 0) {
                    mp.erase(value);
                    count--;
                }
                i++;
            }

            j++;
        }

        return {lhs,rhs};
    }
};

int main(){
    int arr[3][4]={
        {1,4,8,11},
        {2,3,6,10},
        {5,7,12,14}
    };
    int n=4; // total elements in array
    int k=3; // number of arrays
    vector<int>ans;
    // mergeKsortedArrays(arr,n,k,ans);
    helper(arr,n,k,ans);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}