#include<bits/stdc++.h>
using namespace std;

////////OWN SOLUTION
void ksizedWindowMaxMin(int arr[],vector<int>&maxi,vector<int>&mini,int n,int k){ //COMBINED MAX/MIN
    queue<int>q1,q2;
    q1.push(0);
    q2.push(0);

    for(int i=1;i<k;i++){
        if(arr[i]>arr[q1.front()]){
            q1.pop();
            q1.push(i);
        }
        if(arr[i]<arr[q2.front()]){
            q2.pop();
            q2.push(i);
        }
    }
    maxi.push_back(arr[q1.front()]);
    mini.push_back(arr[q2.front()]);

    for(int i=k;i<n;i++){
        if(i-q1.front()>=k){
            q1.pop();
        }
        if(!q1.empty() && arr[i]>arr[q1.front()]){
            q1.pop();
            q1.push(i);
        }
        else{
            q1.push(i);
        }
        maxi.push_back(arr[q1.front()]);

        if(i-q2.front()>=k){
            q2.pop();
        }
        if(!q2.empty() && arr[i]<arr[q2.front()]){
            q2.pop();
            q2.push(i);
        }
        else{
            q2.push(i);
        }
        

        mini.push_back(arr[q2.front()]);
    }
}



////////////////////////////SEPARATE MAX AND MIN FUNCTIONS





void ksizedWindowMax(int arr[],vector<int>&maxi,int n,int k){ //we can merge this 2 fn to get min/max
    queue<int>q;
    q.push(0);

    for(int i=1;i<k;i++){
        if(arr[i]>arr[q.front()]){
            q.pop();
            q.push(i);
        }
    }
    maxi.push_back(arr[q.front()]);

    for(int i=k;i<n;i++){
        if(i-q.front()>=k){
            q.pop();
        }
        if(!q.empty() && arr[i]>arr[q.front()]){
            q.pop();
            q.push(i);
        }
        else{
            q.push(i);
        }
        

        maxi.push_back(arr[q.front()]);
    }
}
void ksizedWindowMin(int arr[],vector<int>&mini,int n,int k){
    queue<int>q;
    q.push(0);

    for(int i=1;i<k;i++){
        if(arr[i]<arr[q.front()]){
            q.pop();
            q.push(i);
        }
    }
    mini.push_back(arr[q.front()]);

    for(int i=k;i<n;i++){
        if(i-q.front()>=k){
            q.pop();
        }
        if(!q.empty() && arr[i]<arr[q.front()]){
            q.pop();
            q.push(i);
        }
        else{
            q.push(i);
        }
        

        mini.push_back(arr[q.front()]);
    }
}

///////////////LAKSHAY BHAIYA'S SOLUTION
int maxminSlidingWindow(vector<int> nums, int k) {
        deque<int>dq,dq2;
        int ans=0;
        
        //processing 1st k elements
        for(int i=0;i<k;i++){
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            while(!dq2.empty() && nums[dq2.back()]>=nums[i]){
                dq2.pop_back();
            }
            dq.push_back(i);
            dq2.push_back(i);
        }

        ans+=nums[dq.front()]+nums[dq2.front()];

        //remaining elements
        for(int i=k;i<nums.size();i++){
            
            //removal
            if(!dq.empty() && i-dq.front()>=k){
                dq.pop_front();
            }
            if(!dq2.empty() && i-dq2.front()>=k){
                dq2.pop_front();
            }
            //addition
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            
            while(!dq2.empty() && nums[dq2.back()]>=nums[i]){
                dq2.pop_back();
            }
            dq.push_back(i);
            dq2.push_back(i);
            ans+=nums[dq.front()]+nums[dq2.front()];
        }

        

        return ans;
    }

int main(){
    int arr[]={2,5,-1,7,-3,-1,-2};
    int n=7;
    int k=4;


    // vector<int>maxi,mini;

    // ksizedWindowMax(arr,maxi,n,k);
    // for(int i=0;i<maxi.size();i++){ //  EITHER THIS OR
    //     cout<<maxi[i]<<" ";
    // }
    // cout<<endl;
    // ksizedWindowMin(arr,mini,n,k);
    // for(int i=0;i<mini.size();i++){
    //     cout<<mini[i]<<" ";
    // }
    // cout<<endl;






    // ksizedWindowMaxMin(arr,maxi,mini,n,k);
    // int sum=0;
    // for(int i=0;i<maxi.size();i++){
    //     sum+= maxi[i] + mini[i];
    // }

    // cout<<sum<<endl;

    vector<int>nums{2,5,-1,7,-3,-1,-2};
    cout<<maxminSlidingWindow(nums,k)<<endl;




}