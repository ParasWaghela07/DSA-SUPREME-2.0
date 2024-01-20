class Solution {
public:

    bool byRecursion(vector<int>&nums,int sum,int index,int &target){
        if(index>=nums.size()){
            return false;
        } 
        if(sum>target){
            return false;
        }
        if(sum==target){
            return true;
        }

        bool in=byRecursion(nums,sum+nums[index],index+1,target);
        bool ex=byRecursion(nums,sum,index+1,target);

        return in||ex;
    }

    bool byMemo(vector<int>&nums,int sum,int index,int &target,vector<vector<int>>&dp){
        if(index>=nums.size()){
            return false;
        } 
        if(sum>target){
            return 0;
        }
        if(sum==target){
            return true;
        }
        if(dp[index][sum]!=-1){
            return dp[index][sum];
        }
        bool in=byMemo(nums,sum+nums[index],index+1,target,dp);
        bool ex=byMemo(nums,sum,index+1,target,dp);

        dp[index][sum] = in||ex;
        return dp[index][sum];
    }

    bool byTabu(vector<int>&nums,int target){
        vector<vector<int>>dp(nums.size()+1,vector<int>(target+1,0));
        
        for(int row=0;row<=nums.size();row++){
            dp[row][target]=1;
        }

        for(int index=nums.size()-1;index>=0;index--){
            for(int sum=target;sum>=0;sum--){
                bool in=0;

                 if(sum+nums[index]<=target)
                 in=dp[index+1][sum+nums[index]];

                 bool ex=dp[index+1][sum];

                 dp[index][sum] = in||ex;
            }
        }
        return dp[0][0];
    }

    bool byTabuSO(vector<int>&nums,int target){
        vector<int>curr(target+1,0);
        vector<int>next(target+1,0);

        curr[target]=1;
        next[target]=1;

        for(int index=nums.size()-1;index>=0;index--){
            for(int sum=target;sum>=0;sum--){
                bool in=0;

                 if(sum+nums[index]<=target)
                 in=next[sum+nums[index]];

                 bool ex=next[sum];

                 curr[sum] = in||ex;
            }
            next=curr;
        }
        return next[0];
    }

    bool canPartition(vector<int>& nums) {
        int TotalSum=0;
        for(int i=0;i<nums.size();i++){
            TotalSum+=nums[i];
        }
        if(TotalSum&1) return false;
        int target=TotalSum/2;
        int index=0;
        int sum=0;

        // vector<vector<bool>>dp(nums.size()+1,vector<bool>(target+1,false));
        // vector<vector<int>>dp(nums.size()+1,vector<int>(target+1,-1));
        // return byMemo(nums,sum,index,target,dp);
        // return byRecursion(nums,sum,index,target);

        // return  byTabu(nums,target);
        return byTabuSO(nums,target);

    }
};