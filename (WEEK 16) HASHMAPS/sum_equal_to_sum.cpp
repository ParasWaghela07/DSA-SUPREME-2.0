int findPairs(long long a[], long long n)
    {
        unordered_map<int,bool>mp;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int sum = a[i] + a[j];
                if(mp[sum]){
                    return true;
                }
                else{
                    mp[sum]=true;
                }
            }
        }
        return false;
    }