class Solution {
public:
    void findSum(vector<int>&nums,int index,int target,vector<vector<int>>&ans){
        int j=index+1;
        int k=nums.size()-1;

        while(j<k){
            if(j>index+1 && nums[j]==nums[j-1]){
                j++;
                continue;
            }
            if(nums[j]+nums[k]==target){
                ans.push_back({nums[index],nums[j],nums[k]});
                j++;
                k--;
            }
            else if(nums[j]+nums[k]<target) j++;
            else k--;
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            findSum(nums,i,nums[i]*-1,ans);
        }

        return ans;
    }
};