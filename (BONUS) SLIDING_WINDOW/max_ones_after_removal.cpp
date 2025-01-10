class Solution {
public:
    --leetcode 1493--

    class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int lastZero=-1;
        int i=0,j=0;
        int ans=0;

        while(j<nums.size()){
            if(nums[j]==0){
                i=lastZero+1;
                lastZero=j;
            }

            ans=max(ans,j-i);
            j++;
        }

        return ans;
    }
};
    int longestSubarray(vector<int>& nums) {
        int ans=0;
        long long zeroes=0;

        int i=0,j=0;
        while(j<nums.size()){
            if(nums[j]==0) zeroes++;
            
            while(zeroes>1){
                if(nums[i]==0) zeroes--;
                i++;
            }
            ans=max(ans,j-i);

            j++;
        }

        return ans;
    }
};

-brute force--
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            bool flag=true;
            for(int j=i;j<nums.size();j++){
                if(nums[j]==0){
                    if(!flag) break;
                    else flag=false;
                }
                ans=max(ans,j-i);
            }
        }

        return ans;
    }
};