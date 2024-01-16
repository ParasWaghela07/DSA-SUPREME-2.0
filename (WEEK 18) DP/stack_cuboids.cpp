class Solution {
public:
    bool check(vector<int>&curr , vector<int>&prev){
        if(curr[0] >= prev[0] && curr[1]>=prev[1] && curr[2]>=prev[2]){
            return true;
        }
        else{
            return false;
        }
    }
    int byTabuSO(vector<vector<int>>&cuboids){
        vector<int>currRow(cuboids.size()+1,0);
        vector<int>nextRow(cuboids.size()+1,0);

        for(int curr=cuboids.size()-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int include=0;
            if(prev==-1 || check(cuboids[curr],cuboids[prev])){
                int heightToAdd=cuboids[curr][2];
                include = heightToAdd + nextRow[curr+1];
            }
            int exclude = 0 + nextRow[prev+1];

            currRow[prev+1]=max(include,exclude);
            }
            nextRow=currRow;
        }

        return nextRow[0];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &it : cuboids){
            sort(it.begin(),it.end());
        }

        sort(cuboids.begin(),cuboids.end());

        int ans = byTabuSO(cuboids);
        return ans;
    }
};