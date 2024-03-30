
class Solution {
public:
    //O(N) O(N)
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans(n);

        for(int i=0;i<n;i++){
            int newIndex=(i+k)%n;
            ans[newIndex]=nums[i];
        }

        nums=ans;
    }
};
//O(N)  O(1)
void rotate(vector<int>& nums, int k) {
    int n=nums.size();
        k=k%n; 

        reverse(nums.begin(),nums.end());
        
        reverse(nums.begin(),nums.begin()+k);
        
        reverse(nums.begin()+k,nums.end());
}