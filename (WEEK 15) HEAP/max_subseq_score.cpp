class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>v;
        for(int i=0;i<nums1.size();i++){
            v.push_back({nums2[i],nums1[i]});
        }

        sort(v.rbegin(),v.rend());
        priority_queue<int,vector<int>,greater<int>>pq;
        long long sum=0;
        for(int i=0;i<k;i++){
            sum+=v[i].second;
            pq.push(v[i].second);
        }
        long long score=sum*v[k-1].first;
        for(int i=k;i<nums1.size();i++){
            sum+=v[i].second;
            sum-=pq.top();
            pq.pop();

            pq.push(v[i].second);
            score=max(score,sum*v[i].first);
        }

        return score;
    }
};

---MIK---
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        
        vector<pair<int,int>> vec(n);
        
        for(int i = 0; i<n; i++) {
            vec[i] = {nums1[i], nums2[i]};
        }
        
        auto lambda = [&](auto &P1, auto &P2) {
            return P1.second > P2.second;
        };
        
        sort(begin(vec), end(vec), lambda);
        
        priority_queue<int, vector<int>, greater<int>> pq; //min_heap
        
        long long Ksum = 0;
        
        for(int i = 0; i<=k-1; i++) {
            
            Ksum += vec[i].first;
            pq.push(vec[i].first);
            
        }
        
        long long result = Ksum * vec[k-1].second;
        
        for(int i = k; i<n; i++) {
            
            //taking minimum as vec[i].second
            Ksum += vec[i].first - pq.top();
            pq.pop();
            
            pq.push(vec[i].first);
            
            result = max(result, Ksum * vec[i].second);
            
        }
        
        return result;
    }
};