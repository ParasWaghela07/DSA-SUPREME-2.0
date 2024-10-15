class Solution {
public:
    void byBS(vector<int>&nums,vector<int>&lis){
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(ans.size()==0 || nums[i]>ans.back()){
                ans.push_back(nums[i]);
                lis.push_back(ans.size());
            }
            else{
                int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[index]=nums[i];
                lis.push_back(index+1);
            }
        }
    }
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int>lis,lds;
        byBS(nums,lis);

        reverse(nums.begin(),nums.end());
        byBS(nums,lds);

        int ans=INT_MIN;

        for(int i=0;i<lis.size();i++){
            if(lis[i]==1 || lds[lds.size()-i-1]==1) continue;

            ans=max(ans,lis[i]+lds[lds.size()-i-1]-1);
        }

        return nums.size()-ans;
    }
};