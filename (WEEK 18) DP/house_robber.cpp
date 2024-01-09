class Solution {
public:
    int byRecursion(vector<int>&nums,int i){
        if(i>=nums.size()){
            return 0;
        }
        int op1=nums[i] + byRecursion(nums,i+2);
        int op2=0+byRecursion(nums,i+1);

        return max(op1,op2);
    }

    int byMemo(vector<int>&nums,int i,vector<int>&dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i] != -1) {
            return dp[i];
        }
        int op1=nums[i] + byMemo(nums,i+2,dp);
        int op2=0+byMemo(nums,i+1,dp);

        dp[i]=max(op1,op2);
        return  dp[i];
    }

    int byTabu(vector<int>&nums){
        int n=nums.size();
        vector<int>dp(n+1,0);///edge case for dp[i+2] going out of bound of array index ie 'n'
        dp[n-1]=nums[n-1];

        for(int i=n-2;i>=0;i--){
            int op1=nums[i] + dp[i+2];
            int op2=0 + dp[i+1];

            dp[i]=max(op1,op2);
        }

        return dp[0];

    }

    int bySS(vector<int>&nums){
        int n=nums.size();
        int prev=nums[n-1];
        int curr=0;
        int next=0;

        for(int i=n-2;i>=0;i--){
            int temp=0;
            if(i+2 < n ){
                temp=next;
            }
            int op1=nums[i] + temp;
            int op2= 0 + prev;
            curr=max(op1,op2);

            next=prev;
            prev=curr;
        }

        return prev;
    }
    int rob(vector<int>& nums) {
        int index=0;
        // int ans=byRecursion(nums,index);

        // vector<int>dp(nums.size(),-1);
        // int ans=byMemo(nums,index,dp);

        // int ans=byTabu(nums);

        int ans=bySS(nums);
        return ans;
    }
};