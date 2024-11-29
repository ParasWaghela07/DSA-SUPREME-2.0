class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        unordered_map<string,int>mp;

        for(int i=0;i<n;i++){
            string s;
            if(matrix[i][0]==0){
                for(auto it:matrix[i]) s.push_back(it+'0');
            }
            else{
                for(auto it:matrix[i]) s.push_back((it^1)+'0');
            }
            mp[s]++;
        }

        int ans=0;
        for(auto it:mp){
            ans=max(ans,it.second);
        }

        return ans;
    }
};