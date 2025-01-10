class Solution {
public:
    --LEETCODE 1014---  optimal solution
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxi=values[0];
        int maxiIndex=0;

        int ans=INT_MIN;

        for(int i=1;i<values.size();i++){
            ans=max(ans,maxi+maxiIndex+values[i]-i);

            if(values[i]+i >= maxi+maxiIndex){
                maxi=values[i];
                maxiIndex=i;
            }
        }

        return ans;
    }
};


--BRUTE FORCE DP --
class Solution {
public:
    int byRec(vector<int>&nums,int count,int index){
        if(count==0) return 0;
        if(index>=nums.size()) return -1e9;

        int in;
        if(count==2) in=nums[index]+index+byRec(nums,count-1,index+1);
        else in=nums[index]-index+byRec(nums,count-1,index+1);

        int ex=byRec(nums,count,index+1);

        return max(in,ex); 
    }

    int byMemo(vector<int>&nums,int count,int index,vector<vector<int>>&dp){
        if(count==0) return 0;
        if(index>=nums.size()) return -1e9;

        if(dp[index][count]!=-1) return dp[index][count];

        int in;
        if(count==2) in=nums[index]+index+byMemo(nums,count-1,index+1,dp);
        else in=nums[index]-index+byMemo(nums,count-1,index+1,dp);

        int ex=byMemo(nums,count,index+1,dp);

        return dp[index][count]=max(in,ex); 
    }

    int maxScoreSightseeingPair(vector<int>& values) {
        // return byRec(values,2,0);

        vector<vector<int>>dp(values.size()+1,vector<int>(3,-1));
        return byMemo(values,2,0,dp);
    }
};