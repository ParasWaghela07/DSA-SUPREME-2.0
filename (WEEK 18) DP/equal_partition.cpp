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

////////////////////
class Solution {
public:
    bool byRec(vector<int>&nums,int sum,int index){
        if(index>=nums.size() || sum<0){
            return false;
        }

        if(sum==0){
            return true;
        }

        bool include=byRec(nums,sum-nums[index],index+1);
        bool exclude=byRec(nums,sum,index+1);

        return include||exclude;
    }
    bool byMem(vector<int>&nums,int sum,int index,vector<vector<int>>&dp){
        if(index>=nums.size() || sum<0){
            return false;
        }

        if(sum==0){
            return true;
        }

        if(dp[sum][index]!=-1) return dp[sum][index];

        bool include=byMem(nums,sum-nums[index],index+1,dp);
        bool exclude=byMem(nums,sum,index+1,dp);

        return dp[sum][index]=include||exclude;
    }
    bool byTabu(vector<int>&nums,int sum){
        vector<vector<bool>>dp(sum+1,vector<bool>(nums.size()+1,false));

        for(int i=0;i<=nums.size();i++){
            dp[0][i]=true;
        }

        for(int curr_sum=0;curr_sum<=sum;curr_sum++){
            for(int index=nums.size()-1;index>=0;index--){
                bool include=0;

                if(curr_sum-nums[index]>=0) include=dp[curr_sum-nums[index]][index+1];

                bool exclude=dp[curr_sum][index+1];

                dp[curr_sum][index]=(include||exclude);
            }
        }

        return dp[sum][0];
    }

    bool bySO(vector<int>&nums,int sum){
        vector<bool>curr(sum+1,0);
        vector<bool>next(sum+1,0);

        curr[0]=1;
        next[0]=1;

    for(int index=nums.size()-1;index>=0;index--){
        for(int curr_sum=0;curr_sum<=sum;curr_sum++){
                bool include=0;

                if(curr_sum-nums[index]>=0) include=next[curr_sum-nums[index]];

                bool exclude=next[curr_sum];

                curr[curr_sum]=(include||exclude);
            }
            next=curr;
        }
        return next[sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto it:nums){
            sum+=it;
        }

        if(sum&1) return false;

        // return byRec(nums,sum/2,0);

        // vector<vector<int>>dp(sum,vector<int>(nums.size()+1,-1));
        // return byMem(nums,sum/2,0,dp);

        // return byTabu(nums,sum/2);

        return bySO(nums,sum/2);
    }
};