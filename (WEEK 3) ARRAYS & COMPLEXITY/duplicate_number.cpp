class Solution {
public:
    O(N) O(1)  --> MODIFIED LITTLE ARRAY
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int index=abs(nums[i]);
            if(nums[index]<0){
                return index;
            }
            nums[index]=nums[index]*-1;
        }

        return -1;
    }

    O(N) O(1)  --> MODIFIED LITTLE ARRAY
    int findDuplicate(vector<int>& nums) {
        while(nums[0]!=nums[nums[0]]){
            swap(nums[0],nums[nums[0]]);
        }

        return nums[0];
    }
};