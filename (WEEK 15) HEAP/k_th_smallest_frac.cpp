class Solution {
public:
---NLOGN

    vector<int> kthSmallestPrimeFraction(vector<int>& nums, int k) {
        priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>,greater<pair<double,pair<int,int>>>>pq;

        for(int i=0;i<nums.size();i++){
            pq.push({1.0*nums[i]/nums[nums.size()-1],{i,nums.size()-1}});
        }

        k--;
        while(k--){
            auto top=pq.top();
            pq.pop();

            int i=top.second.first;
            int j=top.second.second-1;

            pq.push({nums[i]/(nums[j]*1.0),{i,j}});
        }

        return {nums[pq.top().second.first],nums[pq.top().second.second]};
    }
};


class Solution {
public:
    class compare{
        public:
        bool operator()(const auto&a,const auto&b){
            return a.first > b.first;
        }
    };
    ----O(N*LOGN)--
    vector<int> kthSmallestPrimeFraction(vector<int>& nums, int k) {
        priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>,compare>pq;

        pq.push({(nums[0]/nums[nums.size()-1])/1.0,{0,nums.size()-1}});
        k--;
        set<pair<int,int>>st;
        st.insert({0,nums.size()-1});

        while(k--){
            auto top=pq.top();
            pq.pop();

            int i=top.second.first;
            int j=top.second.second;

            // cout<<nums[i]<<","<<nums[j]<<endl;

            if(i+1<j && st.find({i+1,j})==st.end()){
                double frac=(nums[i+1])/(nums[j]/1.0);
                pq.push({frac,{i+1,j}});
                st.insert({i+1,j});
                
                // cout<<"Pushed : "<<frac<<", ["<<nums[i+1]<<","<<nums[j]<<"]"<<endl;
            }

            if(j-1>i && st.find({i,j-1})==st.end()){
                double frac=(nums[i])/(nums[j-1]/1.0);
                pq.push({frac,{i,j-1}});
                st.insert({i,j-1});
                // cout<<"Pushed : "<<frac<<", ["<<nums[i]<<","<<nums[j-1]<<"]"<<endl;
            }


        }

        return {nums[pq.top().second.first],nums[pq.top().second.second]};
    }
};


--o(n*n*logk)--

class Solution {
public:
    class compare{
        public:
        bool operator()(const auto&a,const auto&b){

            return a.first/a.second < b.first/b.second;
        }
    };
    vector<int> kthSmallestPrimeFraction(vector<int>& nums, int k) {
        priority_queue<pair<double,double>,vector<pair<double,double>>,compare>pq;

        for(int i=0;i<nums.size();i++){
            for(int j=nums.size()-1;j>i;j--){
                if(pq.size()<k) pq.push({nums[i],nums[j]});
                else if(pq.top().first/pq.top().second > (nums[i]/nums[j])/1.0){
                    pq.push({nums[i],nums[j]});
                    pq.pop();
                }
                else{
                    break;
                }
            }
        }

        return {(int)pq.top().first,(int)pq.top().second};
    }
};

--brutest force--
class Solution {
public:
    class compare{
        public:
        bool operator()(const auto&a,const auto&b){

            return a.first/a.second < b.first/b.second;
        }
    };
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double,double>,vector<pair<double,double>>,compare>pq;

        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                pq.push({arr[i],arr[j]});
                if(pq.size()>k)pq.pop();
            }
        }

        return {(int)pq.top().first,(int)pq.top().second};
    }
};