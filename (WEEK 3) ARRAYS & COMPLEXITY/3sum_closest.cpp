class Solution {
public:
    int solve(vector<int>&nums,int target,int index){
        int i=index+1;
        int j=nums.size()-1;
        int sum=1e9;
        
        while(i<j){
            int tempSum=nums[i]+nums[j];
            if(tempSum==target) return tempSum;
            else{
                if(abs(tempSum-target)<abs(sum-target)) sum=tempSum;
                if(tempSum>target) j--;
                else i++;
            }
        }
        
        return sum;
    }
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=1e9;
        for(int i=0;i<nums.size();i++){
            int newTarget=target-nums[i];
            int temp=solve(nums,newTarget,i);
            if(abs(temp-newTarget)<abs(ans-target)) ans=temp+nums[i];
        }

        return ans;
    }
};