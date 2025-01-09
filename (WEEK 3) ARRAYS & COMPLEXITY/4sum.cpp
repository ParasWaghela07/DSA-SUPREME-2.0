class Solution {
public:
    void findSum(vector<int>&nums,int index,long long target,vector<vector<int>>&ans,int a,int b){
        int j=index+1;
        int k=nums.size()-1;

        while(j<k){
            if(j>index+1 && nums[j]==nums[j-1]){
                j++;
                continue;
            }
            if(nums[j]+nums[k]==target){
                ans.push_back({a,b,nums[j],nums[k]});
                j++;
                k--;
            }
            else if(nums[j]+nums[k]<target) j++;
            else k--;
        }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
    
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<nums.size();j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                long long halfsum=nums[i]+nums[j];
                long long tosend=target-halfsum;
                findSum(nums,j,tosend,ans,nums[i],nums[j]);
            }
        }

        return ans;
    }
};