class Solution {
public:
    ----BRUTE FORCE--TLE--
    class compare{
        public:
        bool operator()(const vector<int>&a,const vector<int>&b){
            return a[0]+a[1] > b[0]+b[1];
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<vector<int>,vector<vector<int>>,compare>pq;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                pq.push({nums1[i],nums2[j]});

                if(pq.size()>k) pq.pop();
            }
        }

        vector<vector<int>>ans;
        while(k--){
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};

---BRUTE FORCE WORKED---
class Solution {
public:
    class compare{
        public:
        bool operator()(const vector<int>&a,const vector<int>&b){
            return a[0]+a[1] < b[0]+b[1];
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<vector<int>,vector<vector<int>>,compare>pq;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(pq.size() < k) pq.push({nums1[i],nums2[j]});
                else if(pq.top()[0]+pq.top()[1] > nums1[i]+nums2[j]){
                    pq.push({nums1[i],nums2[j]});
                    pq.pop();
                }
                else break;
            }
        }

        vector<vector<int>>ans;
        while(k--){
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};

----OPTIMIZED--
class Solution {
public:

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;

        int i=0;
        int j=0;

        vector<vector<int>>ans;
        pq.push({nums1[0]+nums2[0],0,0});

        set<pair<int,int>>st;

        while(ans.size()<k && !pq.empty()){
            int i=pq.top()[1];
            int j=pq.top()[2];
            pq.pop();

            ans.push_back({nums1[i],nums2[j]});
            if(j+1<nums2.size() && st.find({i,j+1})==st.end()){
                pq.push({nums1[i]+nums2[j+1],i,j+1});
                st.insert({i,j+1});
            }
            if(i+1 < nums1.size() && st.find({i+1,j})==st.end()){
                pq.push({nums1[i+1]+nums2[j],i+1,j});
                st.insert({i+1,j});
            }
        }

        return ans;
    }
};