class Solution {
public:
    --bucket sort---O(N) O(N)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto it:nums) mp[it]++;

        vector<vector<int>>bucket(nums.size()+1);

        //considering index as frq and inserting numbers who have that frq to that index

        for(auto &it:mp){
            int frq=it.second;
            int num=it.first;

            bucket[frq].push_back(num);
        }

        vector<int>ans;
        for(int i=nums.size();i>=0;i--){
            while(bucket[i].size()>0 && k>0){
                ans.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }

        return ans;
    }
};

------O(NLOGK) O(N)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto it:nums) mp[it]++;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto it:mp) {
            if(pq.size()<k) pq.push({it.second,it.first});
            else{
                if(it.second > pq.top().first){
                    pq.pop();
                    pq.push({it.second,it.first});
                }
            }
        }

        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};