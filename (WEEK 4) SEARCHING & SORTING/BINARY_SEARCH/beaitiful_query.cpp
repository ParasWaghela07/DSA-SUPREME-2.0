class Solution {
public:

    int bs(vector<vector<int>>& items,int &limit){
        int s=0;
        int e=items.size()-1;
        int ans=-1;

        while(s<=e){
            int mid=s+(e-s)/2;
            if(items[mid][0]<=limit){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }

        return ans;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        vector<int>prefix;

        vector<int>ans;

        int maxProfit=0;

        for(auto it:items){
            maxProfit=max(maxProfit,it[1]);
            prefix.push_back(maxProfit);
        }

        for(int i=0;i<queries.size();i++){
            int index=bs(items,queries[i]);
            index==-1 ? ans.push_back(0) : ans.push_back(prefix[index]);
        }

        return ans;
    }
};