class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans(n-k+1,-1);

        int count=1;
        for(int i=1;i<k;i++){
            if(nums[i-1]+1==nums[i]) count++;
            else count=1;
        }

        if(count>=k) ans[0]=nums[k-1];
        int i=1;
        int j=k;

        while(j<n){
            if(nums[j-1]+1==nums[j]) count++;
            else count=1;

            if(count>=k) ans[i]=nums[j];

            i++;
            j++;
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;

        for(int i=0;i<nums.size();i++){
            if(dq.size()==k) dq.pop_front();

            if(!dq.empty() && dq.back()!=nums[i]-1) dq.clear();
            dq.push_back(nums[i]); 

            if(i>=k-1){
                
            if(dq.size()==k){
                ans.push_back(dq.back());
            }
            else ans.push_back(-1);
            }
        }

        return ans;
    }
};