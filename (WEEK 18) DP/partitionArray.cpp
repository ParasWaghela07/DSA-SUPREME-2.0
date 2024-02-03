class Solution {
public:
    // int byRecursion(vector<int>&arr,int &k,int s){

    //     if(s>=arr.size()) return 0;
    
    //     int ans=INT_MIN;
    //     for(int i=k;i>0;i--){
    //         int maxi=INT_MIN;
    //         int e=s+i-1;
    //         if(e>=arr.size()){
    //             continue;
    //         }
    //         for(int j=s;j<=e;j++){
    //             maxi=max(arr[j],maxi);
    //         }
    //         ans=max(ans,(maxi*i)+byRecursion(arr,k,e+1));
            
    //     }
    //     return ans;
    // }
    int byMemo(vector<int>&arr,int &k,int s,vector<int>&dp){

        if(s>=arr.size()) return 0;
        if(dp[s]!=-1){
            return dp[s];
        }
    
        int ans=INT_MIN;
        for(int i=k;i>0;i--){
            int maxi=INT_MIN;
            int e=s+i-1;
            if(e>=arr.size()){
                continue;
            }
            for(int j=s;j<=e;j++){
                maxi=max(arr[j],maxi);
            }
            ans=max(ans,(maxi*i)+byMemo(arr,k,e+1,dp));
            
        }
        return dp[s]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // int ans=byRecursion(arr,k,0);
        vector<int>dp(arr.size()+1,-1);
        int ans=byMemo(arr,k,0,dp);
        return ans;
    }
};