class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int i=0;
        int j=0;
        int preZero=0;
        int count=0;
        int sum=0;

        while(j<nums.size()){
            sum+=nums[j];
            while(i<j && (sum>goal || nums[i]==0)){
                if(nums[i]==1){
                    preZero=0;
                }
                else{
                    preZero++;
                }
                sum-=nums[i];
                i++;
            }
            if(sum==goal){
                count+=preZero+1;
            }
            j++;
        }

        return count;
    }
};