class Solution {
public:
    #define MAX 10000000000000LL
    long long byRec(vector<int>&r,vector<int>&f,int rindex,int findex){
        if(rindex>=r.size()) return 0;
        if(findex>=f.size()) return MAX;

        long long include=abs(r[rindex]-f[findex])+byRec(r,f,rindex+1,findex+1);
        long long exclude=byRec(r,f,rindex,findex+1);

        return min(include,exclude);
    }

    long long byMem(vector<int>&r,vector<int>&f,int rindex,int findex,vector<vector<long long>>&dp){
        if(rindex>=r.size()) return 0;
        if(findex>=f.size()) return MAX;
        if(dp[rindex][findex]!=-1) return dp[rindex][findex];

        long long include=abs(r[rindex]-f[findex])+byMem(r,f,rindex+1,findex+1,dp);
        long long exclude=byMem(r,f,rindex,findex+1,dp);

        return dp[rindex][findex]=min(include,exclude);
    }

    long long byTabu(vector<int>&r,vector<int>&f){
        vector<vector<long long>>dp(r.size()+1,vector<long long>(f.size()+1,MAX));
        for(int j=0;j<f.size()+1;j++){
            dp[r.size()][j]=0;
        }

        for(int rindex=r.size()-1;rindex>=0;rindex--){
            for(int findex=f.size()-1;findex>=0;findex--){
                long long include=abs(r[rindex]-f[findex])+dp[rindex+1][findex+1];
                long long exclude=dp[rindex][findex+1];

                dp[rindex][findex]=min(include,exclude);
            }
        }

        return dp[0][0];
    }

    long long bySO(vector<int>&r,vector<int>&f){
        // vector<vector<long long>>dp(r.size()+1,vector<long long>(f.size()+1,MAX));

        vector<long long>curr(f.size()+1,MAX);
        vector<long long>next(f.size()+1,0);

        for(int rindex=r.size()-1;rindex>=0;rindex--){
            for(int findex=f.size()-1;findex>=0;findex--){
                long long include=abs(r[rindex]-f[findex])+next[findex+1];
                long long exclude=curr[findex+1];

                curr[findex]=min(include,exclude);
            }
            next=curr;
        }

        return next[0];
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        vector<int>fact;
        for(auto it:factory){
            while(it[1]--) fact.push_back(it[0]);
        }

        sort(fact.begin(),fact.end());

       
        // return byRec(robot,fact,0,0);

        //  vector<vector<long long>>dp(robot.size(),vector<long long>(fact.size(),-1));
        // return byMem(robot,fact,0,0,dp);


        // return byTabu(robot,fact);

        return bySO(robot,fact);
    }
};