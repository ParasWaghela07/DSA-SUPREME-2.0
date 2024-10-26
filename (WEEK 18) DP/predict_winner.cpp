class Solution {
public:
    int byRec(vector<int>&nums,int s,int e){
        if(s>e) return 0;

        int maxi=0;
        int op1=nums[s]-byRec(nums,s+1,e);
        int op2=nums[e]-byRec(nums,s,e-1);
        maxi=max(op1,op2);

        return maxi;
    }

    int byMem(vector<int>&nums,int s,int e,vector<vector<int>>&dp){
        if(s>e) return 0;
        if(dp[s][e]!=-1) return dp[s][e];

        int maxi=0;
        int op1=nums[s]-byMem(nums,s+1,e,dp);
        int op2=nums[e]-byMem(nums,s,e-1,dp);
        maxi=max(op1,op2);

        return dp[s][e]=maxi;
    }

    int byTabu(vector<int>&nums){
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size(),0));

        for(int s=nums.size()-1;s>=0;s--){
            for(int e=1;e<nums.size();e++){
                if(s>e) continue;

                int maxi=0;
                int op1=nums[s]-dp[s+1][e];
                int op2=nums[e]-dp[s][e-1];
                maxi=max(op1,op2);

                dp[s][e]=maxi;
            }
        }

        return dp[0][nums.size()-1];
    }

    int bySO(vector<int>&nums){
        vector<int>curr(nums.size(),0);
        vector<int>next(nums.size(),0);

        for(int s=nums.size()-1;s>=0;s--){
            for(int e=1;e<nums.size();e++){
                if(s>e) continue;

                int maxi=0;
                int op1=nums[s]-next[e];
                int op2=nums[e]-curr[e-1];
                maxi=max(op1,op2);

                curr[e]=maxi;
            }
            next=curr;
        }

        return next[nums.size()-1];        
    }
    bool predictTheWinner(vector<int>& nums) {
        // return byRec(nums,0,nums.size()-1) >= 0 ? true : false ;

        // vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        // return byMem(nums,0,nums.size()-1,dp)>=0 ? true : false ;

        // return byTabu(nums)>=0 ? true : false ;

        return bySO(nums)>=0 ? 1 :0 ;
    }
};