class Solution {
public:
    vector<int> bruteForce(vector<int>& nums, int k){
        vector<int>ans;
        for(int index=0;index<nums.size();index++){
            int l=index-k;
            int r=index+k;
            if(l<0 || r>=nums.size()) ans.push_back(-1);
            else{
                long long sum=0;
                int windowSize=(2*k)+1;

                for(int i=l;i<=index;i++){
                    sum+=nums[i];
                }

                for(int i=index+1;i<=r;i++){
                    sum+=nums[i];
                }

                ans.push_back(sum/windowSize);
            }
        }

        return ans;
    }
    vector<int> getAverages(vector<int>& nums, int k) {
        // return bruteForce(nums,k);

        vector<int>ans(nums.size(),-1);
        int index=k;

        int windowSize=(2*k)+1;
        long long sum=0;

        int i=0,j=0;
        while(j<nums.size()){
            sum+=nums[j];
            if(j-i+1==windowSize){
                ans[index]=(sum/windowSize);
                index++;
                sum-=nums[i];
                i++;
            }
            j++;
        }

        return ans;
    }
};