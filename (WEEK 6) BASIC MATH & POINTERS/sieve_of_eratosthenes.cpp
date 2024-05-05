class Solution {
public:
    //TIME :- O(N*LOG(LOGN))
    int countPrimes(int n) {
        if(n==0) return 0;
        vector<bool>v(n,true);
        v[0]=v[1]=true;
        int ans=0;

        // for(int i=2;i<n;i++){
        for(int i=2;i<=sqrt(n);i++){ // optimization 2 // means if n=25 , so at i=5 , i*i = 25 , so for values of i>5 there i*i will be always greater than n itself
            if(v[i]){
                ans++;
                // int j=2*i;
                int j=i*i; // optimization 1 // if we checked 2*3 then 3*2 we did not need to check therefore we start with 3*3==i*i
                while(j<n){
                    v[j]=false;
                    j=j+i;
                }
            }
        }

        return ans;
    }
};