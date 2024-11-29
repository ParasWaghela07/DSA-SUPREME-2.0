class Solution {

    int solve(vector<int>& nums,int index,vector<int>&dp){
        int one, two;
        if(index>=nums.size()){
            return 0;
        }
        if(dp[index]!=-1) return dp[index];

        one = (nums[index] + solve(nums,index+2),dp);
        two = (nums[index] + solve(nums,index+3),dp);
        if(one > two){
            return dp[index]=one;
        }else{
            return dp[index]=two;
        }
    

    }
public:
    int rob(vector<int>& nums) {
        
        int zindex,findex;
        vector<int>dp(nums.size()+1,-1);
        zindex = solve(nums,0,dp);
        findex = solve(nums,1,dp);

        if(zindex>findex){
            return zindex;
        }else{
            return findex;
        }

    }
};