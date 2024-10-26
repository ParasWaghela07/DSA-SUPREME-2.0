class Solution {
public:

    LEETCODE 801 
    NAI SAMJA
    int byMem(vector<int>& nums1, vector<int>& nums2,int i,int p1,int p2,vector<vector<int>>&dp,int isSwap){
        if(i==nums1.size()) return 0;

        if(dp[i][isSwap]!=-1) return dp[i][isSwap];

        int swap=INT_MAX , noswap=INT_MAX;

        if(p1<nums2[i] && p2<nums1[i]){
            swap=1+byMem(nums1,nums2,i+1,nums2[i],nums1[i],dp,1);
        }
        if(p1<nums1[i] && p2<nums2[i]){
            noswap=byMem(nums1,nums2,i+1,nums1[i],nums2[i],dp,0);
        }

        return dp[i][isSwap]=min(swap,noswap);
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size()+1,vector<int>(2,-1));
        return byMem(nums1,nums2,0,-1,-1,dp,0);
    }
};