
 --- MAX SUBSEQ HAVIND ADJACENT DIFF EQUAL TO 1 / EQUAL TO K , just change nums[index]>nums[prev] --> abs(nums[index]-nums[prev]==k)
class Solution {
public:
---> IMP -->  WHY PREV IS TAKEN AS INDEX ? TO FORM PROPER DP ARRAY

class Solution {
public:
    int byRec(vector<int>&nums,int prev,int index){
        if(index>=nums.size()) return 0;

        int include=0;
        if(prev==-1 || nums[index]>nums[prev]){
            include=1+byRec(nums,index,index+1);
        }
        int exclude=byRec(nums,prev,index+1);

        return max(include,exclude);
    }

    int byMem(vector<int>&nums,int index,int prev,vector<vector<int>>&dp){
        if(index>=nums.size()) return 0;
        if(dp[index][prev+1]!=-1) return dp[index][prev+1];

        int include=0;
        if(prev==-1 || nums[index]>nums[prev]){
            include=1+byMem(nums,index+1,index,dp);
        }
        int exclude=byMem(nums,index+1,prev,dp);

        return dp[index][prev+1]=max(include,exclude);
    }

    int byTabu(vector<int>&nums){
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,0));

        for(int index=nums.size()-1;index>=0;index--){
            for(int prev=nums.size()-1;prev>=-1;prev--){

                int include=0;
                if(prev==-1 || nums[index]>nums[prev]){
                    include=1+dp[index+1][index+1];
                }
                int exclude=dp[index+1][prev+1];

                dp[index][prev+1]=max(include,exclude);
            }
        }

        return dp[0][0];
    }

    int bySO(vector<int>&nums){
        vector<int>curr(nums.size()+1,0);
        vector<int>next(nums.size()+1,0);

        for(int index=nums.size()-1;index>=0;index--){
            for(int prev=nums.size()-1;prev>=-1;prev--){

                int include=0;
                if(prev==-1 || nums[index]>nums[prev]){
                    include=1+next[index+1];
                }
                int exclude=next[prev+1];

                curr[prev+1]=max(include,exclude);
            }
            next=curr;
        }

        return next[0];
    }

    int bs(vector<int>&ans,int &target){
        int s=0;
        int e=ans.size();
        int index=-1;

        while(s<=e){
            int mid=s+(e-s)/2;
            if(ans[mid]==target) return mid;
            else if(ans[mid]<target){
                s=mid+1;
            }
            else{
                index=mid;
                e=mid-1;
            }
        }

        return index;
    }

    int byBS(vector<int>&nums){
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(ans.size()==0 || ans.back()<nums[i]){
                ans.push_back(nums[i]);
            }
            else{
                int index=bs(ans,nums[i]);
                ans[index]=nums[i];
            }
        }

        return ans.size();
    }

    int lengthOfLIS(vector<int>& nums) {
        // return byRec(nums,-1,0);

        // vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        // return byMem(nums,-1,0,dp);

        // return byTabu(nums);

        // return bySO(nums);

        return byBS(nums);
    }
};


    int byRec(vector<int>&nums,int index,int prev){
        if(index>=nums.size()){
            return 0;
        }

        int include=0;
        if(prev==-1 || nums[index]>nums[prev]){
            include=1+byRec(nums,index+1,index);
        }

        int exclude=byRec(nums,index+1,prev);

        return max(include,exclude);
    }
    int byMem(vector<int>&nums,int index,int prev, vector<vector<int>>&dp){
        if(index>=nums.size()){
            return 0;
        }
        if(dp[index][prev+1]!=-1) return dp[index][prev+1];

        int include=0;
        if(prev==-1 || nums[index]>nums[prev]){
            include=1+byMem(nums,index+1,index,dp);
        }

        int exclude=byMem(nums,index+1,prev,dp);

        return dp[index][prev+1]=max(include,exclude);
    }
    int byTabu(vector<int>&nums){
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,0));

        for(int curr_index=nums.size()-1;curr_index>=0;curr_index--){
            for(int prev_index=curr_index-1;prev_index>=-1;prev_index--){
                int include=0;
                if(prev_index==-1 || nums[curr_index]>nums[prev_index]){
                    include=1+dp[curr_index+1][curr_index+1];
                }

                int exclude=dp[curr_index+1][prev_index+1];

                dp[curr_index][prev_index+1]=max(include,exclude);
            }
        }

        return dp[0][0];
    }

    int bySO(vector<int>&nums){
        vector<int>curr(nums.size()+1,0);
        vector<int>next(nums.size()+1,0);

        for(int curr_index=nums.size()-1;curr_index>=0;curr_index--){
            for(int prev_index=curr_index-1;prev_index>=-1;prev_index--){
                int include=0;
                if(prev_index==-1 || nums[curr_index]>nums[prev_index]){
                    include=1+next[curr_index+1];
                }

                int exclude=next[prev_index+1];

                curr[prev_index+1]=max(include,exclude);
            }

            next=curr;
        }
        return next[0];
    }

    int byBS(vector<int>&nums){
        vector<int>ans;
        ans.push_back(nums[0]);

        for(int i=1;i<nums.size();i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                int index=-1;

                //return index of nums[i] , if exist else return index of number just greater than nums[i]
                index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[index]=nums[i];
            }
        }

        return ans.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        // return byRec(nums,0,-1);

        // vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        // return byMem(nums,0,-1,dp);

        // return byTabu(nums);

        // return bySO(nums);

        return byBS(nums);
    }
};

class Solution {
public:
    int byRecursion(vector<int>&nums,int prev,int curr){
        if(curr>=nums.size()){
            return 0;
        }
        int include=0;
        if(prev==-1 || nums[prev] < nums[curr]){
            include = 1 + byRecursion(nums,curr,curr+1);
        }
        int exclude = 0 + byRecursion(nums,prev,curr+1);

        return max(include,exclude);
    }

    int byMemoisation(vector<int>&nums,int prev,int curr,vector<vector<int>>&dp){
        if(curr>=nums.size()){
            return 0;
        }
        if(dp[curr][prev+1]!=0){
            return dp[prev+1][curr];
        }
        int include=0;
        if(prev==-1 || nums[prev] < nums[curr]){
            include = 1 + byMemoisation(nums,curr,curr+1,dp);
        }
        int exclude = 0 + byMemoisation(nums,prev,curr+1,dp);

        dp[curr][prev+1]=max(include,exclude);
        return  dp[curr][prev+1];
    }

    int ByTabu(vector<int>&nums,vector<vector<int>> &dp){
        for(int curr=nums.size()-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int include=0;
            if(prev==-1 || nums[prev] < nums[curr]){
                include = 1 + dp[curr+1][curr+1];
            }
            int exclude = 0 + dp[curr+1][prev+1];

            dp[curr][prev+1]=max(include,exclude);
            }
        }

        return dp[0][0];
    }

    int byTabuSO(vector<int>&nums){
        vector<int>currRow(nums.size()+1,0);
        vector<int>nextRow(nums.size()+1,0);

        for(int curr=nums.size()-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int include=0;
            if(prev==-1 || nums[prev] < nums[curr]){
                include = 1 + nextRow[curr+1];
            }
            int exclude = 0 + nextRow[prev+1];

            currRow[prev+1]=max(include,exclude);
            }
            nextRow=currRow;
        }

        return nextRow[0];
    }

    int byBS(vector<int>&nums){
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                int index=lower_bound(ans.begin(),ans.end(),nums[i]) - ans.begin();
                ans[index]=nums[i];
            }
        }
        return ans.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        int prev=-1;
        int curr=0;

        int ans=byRecursion(nums,prev,curr);
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,0));

        int ans = byMemoisation(nums,prev,curr,dp);
        int ans = ByTabu(nums,dp);
        int ans = byTabuSO(nums);

        int ans=byBS(nums);
        return ans;
    }
};