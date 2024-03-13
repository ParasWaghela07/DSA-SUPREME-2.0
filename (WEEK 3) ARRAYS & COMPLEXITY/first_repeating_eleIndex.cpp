int firstRepeated(int arr[], int n) {
        unordered_map<int,int>mp;
        int index=n;
        for(int i=0;i<n;i++){
            if(mp.find(arr[i])!=mp.end()){
                index=min(index,mp[arr[i]]);
            }
            else{
                mp[arr[i]]=i;
            }
        }
        if(index==n) return -1;
        return index+1;
    }