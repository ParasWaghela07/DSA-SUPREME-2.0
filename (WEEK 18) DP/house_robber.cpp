
class Solution {
public:
    int byRec(vector<int>&nums,int index){
        if(index>=nums.size()){
            return 0;
        }
        int include=nums[index]+byRec(nums,index+2);
        int exclude=byRec(nums,index+1);
        return max(include,exclude);
    }
    int byMem(vector<int>&nums,int index,vector<int>&dp){
        if(index>=nums.size()){
            return 0;
        }
        if(dp[index]!=-1) return dp[index];

        int include=nums[index]+byMem(nums,index+2,dp);
        int exclude=byMem(nums,index+1,dp);
        return dp[index]=max(include,exclude);
    }
    int byTabu(vector<int>&nums){
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);

        vector<int>dp(nums.size(),-1);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);

        for(int i=2;i<nums.size();i++){
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
        }
        return dp[nums.size()-1];
    }
        int byMem(vector<int>&nums,int index,vector<int>&dp){
        if(index>=nums.size()){
            return 0;
        }
        if(dp[index]!=-1) return dp[index];

        int include=nums[index]+byMem(nums,index+2,dp);
        int exclude=byMem(nums,index+1,dp);
        return dp[index]=max(include,exclude);
    }
    int byTabu(vector<int>&nums){
        vector<int>dp(nums.size(),-1);
        int n=nums.size();
        dp[n-1]=nums[n-1];

        for(int i=n-2;i>=0;i--){

            int include=nums[i];
            if(i+2<n) include+=dp[i+2];

            int exclude=dp[i+1];

            dp[i]=max(include,exclude);
        }

        return dp[0];
    }
    int bySo(vector<int>&nums){
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);

        int prev=nums[0];
        int curr=max(nums[0],nums[1]);
        int ans=INT_MIN;

        for(int i=2;i<nums.size();i++){
            ans=max(prev+nums[i],curr);
            prev=curr;
            curr=ans;
        }

        return ans;
    }

    int bySo(vector<int>&nums){
        
        int plusTwo=0;
        int plusOne=nums[nums.size()-1];
        int curr=nums[nums.size()-1];

        for(int i=nums.size()-2;i>=0;i--){
            curr=max(nums[i]+plusTwo,plusOne);
            plusTwo=plusOne;
            plusOne=curr;
        }

        return curr;
    }

    int rob(vector<int>& nums) {
        // return byRec(nums,0);

        // vector<int>dp(nums.size(),-1);
        // return byMem(nums,0,dp);

        // return byTabu(nums);

        return bySo(nums);
    }
};

/////////////////////////////////


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