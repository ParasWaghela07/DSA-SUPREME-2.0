class Solution {
    public:
        lc-1920
        vector<int> buildArray(vector<int>& nums) {
            int n=nums.size();
            for(int i=0;i<nums.size();i++){
                int old=nums[i];
                int New=nums[nums[i]]%n;
                nums[i]=(old+(n*New));
            }
    
            for(int i=0;i<nums.size();i++){
                nums[i]=nums[i]/n;
            }
    
            return nums;
    
            return nums;
        }
    };