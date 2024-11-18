    int missingNumber(int arr[], int n)
    
    { 
        sort(arr,arr+n);
        int num=1;
        for(int i=0;i<n;i++){
            if(arr[i]==num) num++;
        }
        
        return num;
    } 

        int missingNumber(int arr[], int n) 
    { 
        unordered_map<int,bool>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]=true;
        }
        
        int num=1;
        while(mp.find(num)!=mp.end()){
            num++;
        }
        
        return num;
    } 