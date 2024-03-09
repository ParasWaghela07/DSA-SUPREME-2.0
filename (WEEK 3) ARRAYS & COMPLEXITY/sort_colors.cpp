class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        int index=0;

        while(index<=j){
            if(nums[index]==0){
                swap(nums[i],nums[index]);
                i++;
                index++;
            }
            else if(nums[index]==2){
                swap(nums[j],nums[index]);
                j--;
            }
            else{
                index++;
            }
        }

        return;
    }
};