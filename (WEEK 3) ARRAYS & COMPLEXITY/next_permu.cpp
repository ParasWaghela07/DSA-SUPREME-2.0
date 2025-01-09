class Solution {
public:
    void dosort(vector<int>&nums,int index){
        
        for(int i=index;i<nums.size();i++){
            for(int j=index;j<nums.size()-1;j++){
                if(nums[j]>nums[j+1]) swap(nums[j],nums[j+1]);
            }
        }
    }
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int index=-1;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                index=i-1;
                break;
            }
        }

        if(index==-1){
            reverse(nums.begin(),nums.end());
            return;
        }

        //APPROACH-1
        int num=nums[index];
        int swappable=-1;
        for(int i=index+1;i<nums.size();i++){
            if(nums[i]>num && (swappable==-1 || nums[i]<nums[swappable])){
                swappable=i;
            }
        }

        swap(nums[index],nums[swappable]);
        dosort(nums,index+1);
        return;

        //APPROACH-2
        for(int i=n-1; i>index; i--){
            if(nums[i]>nums[index]){
                swap(nums[i], nums[index]);
                break;
            }
        }

        reverse(nums.begin()+index+1, nums.end());
    }
};