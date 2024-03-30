class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=1;

        int count=0;

        while(j<nums.size()){
            int diff=abs(nums[i]-nums[j]);

            if(diff==k){
                count++;
                int curr=nums[j];
                while(j<nums.size() && nums[j]==curr){
                    j++;
                }
            }
            else if(diff<k){
                j++;
            }
            else{
                i++;
            }

            if(i==j){
                j++;
            }
        }

        return count;
    }
};