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

    class Solution {
public:
    int byRec(vector<int>&days,vector<int>&costs,int index){
        if(index>=days.size()) return 0;

        int op1=costs[0]+byRec(days,costs,index+1);

        int validity=days[index]+6;
        int j=index;
        while(j<days.size() && days[j]<=validity) j++;

        int op2=costs[1]+byRec(days,costs,j);

        validity=days[index]+29;
        j=index;
        while(j<days.size() && days[j]<=validity) j++;

        int op3=costs[2]+byRec(days,costs,j);

        return min(min(op1,op2),op3);
    }

    int byMem(vector<int>&days,vector<int>&costs,int index,vector<int>&dp){
        if(index>=days.size()) return 0;

        if(dp[index]!=-1) return dp[index];

        int op1=costs[0]+byMem(days,costs,index+1,dp);

        int validity=days[index]+6;
        int j=index;
        while(j<days.size() && days[j]<=validity) j++;

        int op2=costs[1]+byMem(days,costs,j,dp);

        validity=days[index]+29;
        j=index;
        while(j<days.size() && days[j]<=validity) j++;

        int op3=costs[2]+byMem(days,costs,j,dp);

        return dp[index]=min(min(op1,op2),op3);
    }

    int byTabu(vector<int>&days,vector<int>&costs){
        vector<int>dp(days.size()+1,0);
        for(int index=days.size()-1;index>=0;index--){
            int op1=costs[0]+dp[index+1];

            int validity=days[index]+6;
            int j=index;
            while(j<days.size() && days[j]<=validity) j++;

            int op2=costs[1]+dp[j];

            validity=days[index]+29;
            j=index;
            while(j<days.size() && days[j]<=validity) j++;

            int op3=costs[2]+dp[j];

            dp[index]=min(min(op1,op2),op3);
        }

        return dp[0];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // return byRec(days,costs,0);

        // vector<int>dp(days.size()+1,-1);
        // return byMem(days,costs,0,dp);

        return byTabu(days,costs);
    }
};