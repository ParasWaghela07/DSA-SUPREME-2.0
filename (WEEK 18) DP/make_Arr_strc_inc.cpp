class Solution {
public:
    int byRec(vector<int>& arr1, vector<int>& arr2,int prev,int curr){
        if(curr>=arr1.size()) return 0;

        int op1=1e9+1;
        if(prev<arr1[curr]){
            op1=byRec(arr1,arr2,arr1[curr],curr+1);
        }

        int op2=1e9+1;
        auto index=upper_bound(arr2.begin(),arr2.end(),prev);
        if(index!=arr2.end()) op2=1+byRec(arr1,arr2,arr2[index-arr2.begin()],curr+1);

        return min(op1,op2);
    }

    int byMem(vector<int>& arr1, vector<int>& arr2,int prev,int curr,map<pair<int,int>,int>&dp){
        if(curr>=arr1.size()) return 0;
        if(dp.find({prev,curr})!=dp.end()) return dp[{prev,curr}];

        int op1=1e9+1;
        if(prev<arr1[curr]){
            op1=byMem(arr1,arr2,arr1[curr],curr+1,dp);
        }

        int op2=1e9+1;
        auto index=upper_bound(arr2.begin(),arr2.end(),prev);
        if(index!=arr2.end()) op2=1+byMem(arr1,arr2,arr2[index-arr2.begin()],curr+1,dp);

        return dp[{prev,curr}]=min(op1,op2);
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        // int ans = byRec(arr1,arr2,-1,0);

        map<pair<int,int>,int>dp;
        int ans = byMem(arr1,arr2,-1,0,dp);

        return ans==1e9+1 ? -1 : ans;
    }
};