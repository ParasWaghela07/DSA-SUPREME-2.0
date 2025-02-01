leetcode-2948

//MINE OPTIMAL
--O(NLOGN)--O(3N)
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int>temp=nums;
        unordered_map<int,priority_queue<int,vector<int>,greater<>>>mp;
        unordered_map<int,int>element_to_grp;
        sort(temp.begin(),temp.end());
        vector<int>ans;

        int grp=0;
        mp[grp].push(temp[0]);
        element_to_grp[temp[0]]=grp;
        for(int i=1;i<temp.size();i++){
            if(abs(temp[i]-temp[i-1])>limit) grp++;
            mp[grp].push(temp[i]);
            element_to_grp[temp[i]]=grp;
        }

        for(int i=0;i<nums.size();i++){
            int grpNo=element_to_grp[nums[i]];
            int toAdd=mp[grpNo].top();
            mp[grpNo].pop();

            ans.push_back(toAdd);
        }

        return ans;
    }
};

--using list
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int>temp=nums;
        unordered_map<int,list<int>>mp;
        unordered_map<int,int>element_to_grp;
        sort(temp.begin(),temp.end());
        vector<int>ans;

        int grp=0;
        mp[grp].push_back(temp[0]);
        element_to_grp[temp[0]]=grp;
        for(int i=1;i<temp.size();i++){
            if(abs(temp[i]-temp[i-1])>limit) grp++;
            mp[grp].push_back(temp[i]);
            element_to_grp[temp[i]]=grp;
        }

        for(int i=0;i<nums.size();i++){
            int grpNo=element_to_grp[nums[i]];
            int toAdd=*mp[grpNo].begin();
            mp[grpNo].pop_front();
            ans.push_back(toAdd);
        }

        return ans;
    }
};


--brute force
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int>v=nums;
        int i=0;

        while(i<v.size()){
            bool flag=true;
            for(int j=i+1;j<v.size();j++){
                if(v[j]<v[i] && abs(v[i]-v[j])<=limit){
                    swap(v[i],v[j]);
                    flag=false;
                }
            }
            if(flag) i++;
        }

        return v;
    }
};