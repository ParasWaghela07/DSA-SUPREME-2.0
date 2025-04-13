class Solution {
    public: 
        long long mod=1e9+7;
        int power(long long a,long long b){
            if(b==0) return 1;
    
            long long half=power(a,b/2)%mod;
            long long res=(half*half)%mod;
    
            if(b&1) res=(res*a)%mod;
    
            return res;
        }
        int countGoodNumbers(long long n) {
            long long even=(n+1)/2;
            long long odd=n/2;
            
    
            long long a=power(5,even);
            long long b=power(4,odd);
    
            return (a*b)%mod;
        }
    };