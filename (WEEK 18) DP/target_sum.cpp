class Solution {
public:
    int byRec(vector<int>&nums,int target,int index,int sum){
        if(index>=nums.size() && target==sum) return 1;
        if(index>=nums.size() && target!=sum) return 0;

        int op1=byRec(nums,target,index+1,sum+nums[index]);
        int op2=byRec(nums,target,index+1,sum-nums[index]);

        return op1+op2;
    }

    int byMem(vector<int>&nums,int target,int index,int sum,map<pair<int,int>,int>&dp){
        if(index>=nums.size() && target==sum) return 1;
        if(index>=nums.size() && target!=sum) return 0;

        if(dp.find({index,sum})!=dp.end()) return dp[{index,sum}];

        int op1=byMem(nums,target,index+1,sum+nums[index],dp);
        int op2=byMem(nums,target,index+1,sum-nums[index],dp);

        return dp[{index,sum}]=op1+op2;
    }

    int byTabu(vector<int>&nums,int target){
        map<pair<int,int>,int>dp;
        dp[{nums.size(),target}]=1;

        int temp=0;
        for(auto it:nums) temp+=it;

        for(int index=nums.size()-1;index>=0;index--){
            for(int sum=temp;sum>=-temp;sum--){
                
                int op1=0;
                int op2=0;

                if(dp.find({index+1,sum+nums[index]})!=dp.end()) op1=dp[{index+1,sum+nums[index]}];
                if(dp.find({index+1,sum-nums[index]})!=dp.end()) op2=dp[{index+1,sum-nums[index]}];

                dp[{index,sum}]=op1+op2;
            }
        }

        return dp[{0,0}];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        // return byRec(nums,target,0,0);

        
        // map<pair<int,int>,int>dp;
        // return byMem(nums,target,0,0,dp);

        return byTabu(nums,target);
    }

};