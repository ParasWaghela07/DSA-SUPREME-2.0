


class Solution {
public:
    int byRec(vector<int>& nums,int s,int e){
        if(s>e) return 0;

        int coins=INT_MIN;
        for(int i=s;i<=e;i++){
            coins=max(coins,nums[s-1]*nums[i]*nums[e+1] + byRec(nums,s,i-1) + byRec(nums,i+1,e));
        }

        return coins;
    }
    int byMem(vector<int>& nums,int s,int e,vector<vector<int>>&dp){
        if(s>e) return 0;
        if(dp[s][e]!=-1) return dp[s][e];
        int coins=INT_MIN;
        for(int i=s;i<=e;i++){
            coins=max(coins,nums[s-1]*nums[i]*nums[e+1] + byMem(nums,s,i-1,dp) + byMem(nums,i+1,e,dp));
        }

        return dp[s][e]=coins;
    }

    int byTabu(vector<int>&nums){
         vector<vector<int>>dp(nums.size()+3,vector<int>(nums.size()+3,0));

         for(int s=nums.size()-2;s>=1;s--){
            for(int e=1;e<=nums.size()-2;e++){
                if(s>e) continue;

                    int coins=INT_MIN;
                    for(int i=s;i<=e;i++){
                        coins=max(coins,nums[s-1]*nums[i]*nums[e+1] + dp[s][i-1] + dp[i+1][e]);
                    }

                    dp[s][e]=coins;
            }
         }

         return dp[1][nums.size()-2];
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);

        // return byRec(nums,1,nums.size()-2);

        // vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        // return byMem(nums,1,nums.size()-2,dp);

        return byTabu(nums);
    }
};


//NOT ACCEPTED
class Solution {
public:
    int byRec(vector<int>&nums){
        if(nums.size()==0) return 0;

        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int leftOne= i-1>=0 ? nums[i-1] : 1;
            int rightOne=i+1<nums.size()?nums[i+1]:1;

            vector<int>temp;
            for(int j=0;j<nums.size();j++){
                if(j==i) continue;
                temp.push_back(nums[j]);
            }
            ans=max(ans,(leftOne*nums[i]*rightOne) + byRec(temp));
        }

        return ans;
    }
    int byMem(vector<int>&nums, map<vector<int>,int>&dp){
        if(nums.size()==0) return 0;
        if(dp.find(nums)!=dp.end()) return dp[nums];

        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int leftOne= i-1>=0 ? nums[i-1] : 1;
            int rightOne=i+1<nums.size()?nums[i+1]:1;

            vector<int>temp;
            for(int j=0;j<nums.size();j++){
                if(j==i) continue;
                temp.push_back(nums[j]);
            }
            ans=max(ans,(leftOne*nums[i]*rightOne) + byMem(temp,dp));
        }

        return dp[nums]=ans;
    }
    int maxCoins(vector<int>& nums) {
        
        // return byRec(nums);

        map<vector<int>,int>dp;
        return byMem(nums,dp);
    }
};