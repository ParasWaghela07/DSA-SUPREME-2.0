class Solution {
public:
    bool valid(vector<int>&curr,vector<int>&prev){
        if(curr[0]>prev[0] && curr[1]>prev[1]) return true;
        else return false;
    }
    int byRec(vector<vector<int>>& env,int curr,int prev){
        if(curr>=env.size()) return 0;

        int include=0;
        if(prev==-1 || valid(env[curr],env[prev])){
            include=1 + byRec(env,curr+1,curr);
        }
        int exclude=byRec(env,curr+1,prev);

        return max(include,exclude);
    }
    int byMem(vector<vector<int>>& env,int curr,int prev,vector<vector<int>>&dp){
        if(curr>=env.size()) return 0;
        if(dp[curr][prev+1]!=-1) return dp[curr][prev+1];

        int include=0;
        if(prev==-1 || valid(env[curr],env[prev])){
            include=1+ byMem(env,curr+1,curr,dp);
        }
        int exclude=byMem(env,curr+1,prev,dp);

        return dp[curr][prev+1]=max(include,exclude);
    }

    int byTabu(vector<vector<int>>& env){
        vector<vector<int>>dp(env.size()+1,vector<int>(env.size()+1,0));

        for(int curr=env.size()-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int include=0;
                if(prev==-1 || valid(env[curr],env[prev])){
                    include=1+ dp[curr+1][curr+1];
                }
                int exclude=dp[curr+1][prev+1];

                dp[curr][prev+1]=max(include,exclude);
            }
        }

        return dp[0][0];
    }

    int bySO(vector<vector<int>>& env){
        vector<int>curr(env.size()+1,0);
        vector<int>next(env.size()+1,0);

        for(int curr_index=env.size()-1;curr_index>=0;curr_index--){
            for(int prev=curr_index-1;prev>=-1;prev--){
                int include=0;
                if(prev==-1 || valid(env[curr_index],env[prev])){
                    include=1 + next[curr_index+1];
                }
                int exclude=next[prev+1];

                curr[prev+1]=max(include,exclude);
            }
            next=curr;
        }

        return next[0];
    }

    int bs(vector<int>&ans ,int&target){
        int s=0;
        int e=ans.size()-1;
        int index=-1;

        while(s<=e){
            int mid=s+(e-s)/2;
            if(ans[mid]>=target){
                index=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }

        return index;
    }

    static bool comp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]) return a[1] > b[1];
        else return a[0]<b[0];
    }

    int byBS(vector<vector<int>>& env){
        vector<int>ans;
        for(int i=0;i<env.size();i++){
            if(ans.size()==0 || env[i][1]>ans.back()){
                ans.push_back(env[i][1]);
            }
            else{
                int index=bs(ans,env[i][1]);
                ans[index]=env[i][1];
            }
        }

        return ans.size();
    }
    int maxEnvelopes(vector<vector<int>>& env) {

        // sort(env.begin(),env.end());

        // return byRec(env,0,-1);

        // vector<vector<int>>dp(env.size()+1,vector<int>(env.size()+1,-1));
        // return byMem(env,0,-1,dp);

        // return byTabu(env);

        // return bySO(env);

        sort(env.begin(),env.end(),comp);
        return byBS(env);
    }
};