class Solution{
  public:
    int maxLen(int arr[], int N)
    {
        unordered_map<int,int>mp;
        int ans=0;
        int sum=0;
        
        for(int i=0;i<N;i++){
            if(arr[i]==0) sum--;
            else sum++;
            if(sum==0) ans=max(ans,i+1);
            if(mp.find(sum)==mp.end()){
                mp[sum]=i;
            }
            else{
                ans=max(ans,i-mp[sum]);
            }
            
        }
        
        return ans;
    }
};