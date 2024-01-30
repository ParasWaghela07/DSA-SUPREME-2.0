class Solution {
public:
    // int byRecursion(vector<int>& days,vector<int>&costs,int i,int day){
    //     if(i>=days.size()){
    //         return 0;
    //     }
    //     int ans=INT_MAX;
    //     if(days[i]>day){
    //         int op1=costs[0]+byRecursion(days,costs,i+1,days[i]);
    //         int op2=costs[1]+byRecursion(days,costs,i+1,days[i]+6);
    //         int op3=costs[2]+byRecursion(days,costs,i+1,days[i]+29);

    //         ans=min(op1,min(op2,op3));
    //     }
    //     else{
    //         ans= 0 + byRecursion(days,costs,i+1,day);
    //     }

    //     return ans;
    // }
    int byMemo(vector<int>& days,vector<int>&costs,int i,int day,vector<vector<int>>&dp){
        if(i>=days.size()){
            return 0;
        }
        if(dp[i][day]!=-1){
            return dp[i][day];
        }
        int ans=INT_MAX;
        if(days[i]>day){
            int op1=costs[0]+byMemo(days,costs,i+1,days[i],dp);
            int op2=costs[1]+byMemo(days,costs,i+1,days[i]+6,dp);
            int op3=costs[2]+byMemo(days,costs,i+1,days[i]+29,dp);

            ans=min(op1,min(op2,op3));
        }
        else{
            ans= 0 + byMemo(days,costs,i+1,day,dp);
        }

        return dp[i][day]=ans;
    }

    int lakshayB(vector<int>&days,vector<int>&costs,int i,vector<int>&dp){
        if(i>=days.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        //1 day
        int cost1=costs[0]+lakshayB(days,costs,i+1,dp);

        //7 day
        int passEnd=days[i]+6;
        int j=i;
        while(j<days.size() && days[j]<=passEnd){
            j++;
        }
        int cost7=costs[1]+lakshayB(days,costs,j,dp);

        //30 day
        passEnd=days[i]+29;
        j=i;
        while(j<days.size() && days[j]<=passEnd){
            j++;
        }
        int cost30=costs[2]+lakshayB(days,costs,j,dp);

        return dp[i]=min(cost1,min(cost7,cost30));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
       int i=0;
       int day=0;
    //    int ans=lakshayB(days,costs,i);
       vector<vector<int>>dp(days.size(),vector<int>(400,-1));
    // vector<int>dp(days.size()+1,-1);
    //    int ans=lakshayB(days,costs,i,dp);
       int ans=byMemo(days,costs,i,day,dp);
    //    int ans=byRecursion(days,costs,i,day);
       return ans;
    }
};