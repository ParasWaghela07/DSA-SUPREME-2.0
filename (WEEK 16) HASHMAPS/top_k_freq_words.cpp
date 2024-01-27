class Solution {
public:
class compare{
    public:
    bool operator()(auto a,auto b){
        if(a.second != b.second)
        return a.second < b.second;
        else
        return a.first > b.first;
    }
};
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string>ans;
        unordered_map<string,int>mp;
        for(auto it:words){
            mp[it]++;
        }

        priority_queue<pair<string,int>,vector<pair<string,int>>,compare>pq;

        for(auto it:mp){
            pq.push({it.first,it.second});
        }

        while(k--){
            auto top=pq.top(); pq.pop();
            ans.push_back(top.first);
        }

        return ans;
    }
};