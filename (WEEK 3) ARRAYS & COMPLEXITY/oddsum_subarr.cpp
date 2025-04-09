class Solution {
    public:
        int numOfSubarrays(vector<int>& arr) {
            int mod=1e9+7;
            int sum=0;
    
            int evenCount=1;
            int oddCount=0;
    
            int ans=0;
    
            for(auto it:arr){
                sum+=it;
    
                if(sum&1){
                    ans=(ans+evenCount)%mod;
                    oddCount++;
                }
                else{
                    ans=(ans+oddCount)%mod;
                    evenCount++;
                }
            }
    
            return ans;
        }
    };