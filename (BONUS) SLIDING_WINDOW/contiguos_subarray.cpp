class Solution {
public:
    class compare{
        public:
        bool operator()(pair<int,int>&a,pair<int,int>&b){
            if(a.first==b.first) return a.second < b.second;
            else return a.first > b.first;
        }
    };
    long long continuousSubarrays(vector<int>& nums) {
        long long ans=0;
    
        priority_queue<pair<int,int>>maxi;
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare>mini;

        int i=0;
        int j=0;

        while(j<nums.size()){
            if(!mini.empty() && abs(nums[j]-mini.top().first)>2){
                int index=mini.top().second;
                mini.pop();

                i=index+1;
                while(!mini.empty() && mini.top().second < i ) mini.pop();
            }

            if(!maxi.empty() && abs(nums[j]-maxi.top().first)>2){
                int index=maxi.top().second;
                maxi.pop();

                i=index+1;
                while(!maxi.empty() && maxi.top().second < i ) maxi.pop();
            }

            mini.push({nums[j],j});
            maxi.push({nums[j],j});

            ans+=(j-i+1);
            j++;
        }

        return ans;
    }
};