//CHECKING ALSO THAT SAME NUMBER SHOULD NOT BE ADDED WITH ITSELF
//O(N) O(N)
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    unordered_map<int,int>mp;
	    for(int i=0;i<n;i++){
	        mp[arr[i]]=i;
	    }
	    
	    for(int i=0;i<n;i++){
	        int target=x-arr[i];
	        if(mp[target] && mp[target]!=i){
	            return true;
	        }
	    }
	    
	    return false;
	}

    //O(NLOGN) O(1)
    bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    sort(arr,arr+n);
	    int i=0;
	    int j=n-1;
	    
	    while(i<j){
	        if(arr[i]+arr[j]==x){
	            return true;
	        }
	        else if(arr[i]+arr[j]<x){
	            i++;
	        }
	        else{
	            j--;
	        }
	    }
	    
	    return false;
	}

