class Solution {
public:
    bool valid(vector<int>&curr,vector<int>&prev){
        if(curr[0]>=prev[0] && curr[1]>=prev[1] && curr[2]>=prev[2]) return true;
        else return false;
    }
    int byRec(vector<vector<int>>& cuboids,int curr,int prev){
        if(curr>=cuboids.size()) return 0;

        int include=0;
        if(prev==-1 || valid(cuboids[curr],cuboids[prev])){
            include=cuboids[curr][2] + byRec(cuboids,curr+1,curr);
        }
        int exclude=byRec(cuboids,curr+1,prev);

        return max(include,exclude);
    }
    int byMem(vector<vector<int>>& cuboids,int curr,int prev,vector<vector<int>>&dp){
        if(curr>=cuboids.size()) return 0;
        if(dp[curr][prev+1]!=-1) return dp[curr][prev+1];

        int include=0;
        if(prev==-1 || valid(cuboids[curr],cuboids[prev])){
            include=cuboids[curr][2] + byMem(cuboids,curr+1,curr,dp);
        }
        int exclude=byMem(cuboids,curr+1,prev,dp);

        return dp[curr][prev+1]=max(include,exclude);
    }

    int byTabu(vector<vector<int>>& cuboids){
        vector<vector<int>>dp(cuboids.size()+1,vector<int>(cuboids.size()+1,0));

        for(int curr=cuboids.size()-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int include=0;
                if(prev==-1 || valid(cuboids[curr],cuboids[prev])){
                    include=cuboids[curr][2] + dp[curr+1][curr+1];
                }
                int exclude=dp[curr+1][prev+1];

                dp[curr][prev+1]=max(include,exclude);
            }
        }

        return dp[0][0];
    }

    int bySO(vector<vector<int>>& cuboids){
        vector<int>curr(cuboids.size()+1,0);
        vector<int>next(cuboids.size()+1,0);

        for(int curr_index=cuboids.size()-1;curr_index>=0;curr_index--){
            for(int prev=curr_index-1;prev>=-1;prev--){
                int include=0;
                if(prev==-1 || valid(cuboids[curr_index],cuboids[prev])){
                    include=cuboids[curr_index][2] + next[curr_index+1];
                }
                int exclude=next[prev+1];

                curr[prev+1]=max(include,exclude);
            }
            next=curr;
        }

        return next[0];
    }
    
    int maxHeight(vector<vector<int>>& cuboids) {

        for(auto &it:cuboids){
            sort(it.begin(),it.end());
        }
        sort(cuboids.begin(),cuboids.end());

        // return byRec(cuboids,0,-1);

        // vector<vector<int>>dp(cuboids.size()+1,vector<int>(cuboids.size()+1,-1));
        // return byMem(cuboids,0,-1,dp);

        // return byTabu(cuboids);

        return bySO(cuboids);
    }
};