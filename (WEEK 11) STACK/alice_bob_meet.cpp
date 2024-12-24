class Solution {
public:
    --brute force--O(N*N)
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n=heights.size();
        vector<int>ans;
        for(auto it:queries){
            int i=it[0];
            int j=it[1];

            if(i==j){
                ans.push_back(i);
                continue;
            }

            if(j<i) swap(i,j);

            while(j<n && heights[j]<=heights[i])j++;

            if(j==n) ans.push_back(-1);
            else ans.push_back(j);
        }

        return ans;
    }
};

