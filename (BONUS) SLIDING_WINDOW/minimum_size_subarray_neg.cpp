class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<int>dq;
        vector<long long>prefix(nums.size(),0);
        int j=0;

        int ans=INT_MAX;

        while(j<nums.size()){
            if(j==0){
                prefix[j]=nums[j];
            }
            else{
                prefix[j]=prefix[j-1]+nums[j];
            }

            if(prefix[j]>=k) ans=min(ans,j+1);
           
            while(!dq.empty() && prefix[j]-prefix[dq.front()]>=k){
                ans=min(ans,j-dq.front());
                dq.pop_front();
            }

            while(!dq.empty() && prefix[j] <= prefix[dq.back()]) dq.pop_back();

            dq.push_back(j);

            j++;
        }

        return ans==INT_MAX ? -1 : ans;
    }
};


class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<int>dq;
        vector<long long>prefix;
        int j=0;

        int ans=INT_MAX;
        int sum=0;

        while(j<nums.size()){
            sum+=nums[j];
            prefix.push_back(sum);

            if(sum>=k) ans=min(ans,j+1);
           
            while(!dq.empty() && sum-prefix[dq.front()]>=k){
                ans=min(ans,j-dq.front());
                dq.pop_front();
            }

            while(!dq.empty() && sum <= prefix[dq.back()]) dq.pop_back();

            dq.push_back(j);

            j++;
        }

        return ans==INT_MAX ? -1 : ans;
    }
};