class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        
        for(int index=0;index<n; index++) {
            sum = sum + nums[index];
        }

        int totalSum = ((n)*(n+1))/2;
        int ans = totalSum - sum;
        return ans;
    }
};
    //BITWISE XOR
    class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=ans^nums[i];
        }

        for(int i=0;i<=nums.size();i++){
            ans=ans^i;
        }

        return ans;
    }
};