
string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[a1[i]]++;
    }
   
    for(int i=0;i<m;i++){
        if(mp[a2[i]]<=0) return "No";
        mp[a2[i]]--;
    }
   
    return "Yes";
}


string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int,int>mp;
    for(int i=0;i<m;i++){
        mp[a2[i]]++;
    }
    for(int i=0;i<n;i++){
        if(mp.find(a1[i])!=mp.end()){
            mp[a1[i]]--;
        }
    }
    for(auto it:mp){
        if(it.second > 0){
            return "No";
        }
    }
    return "Yes";
}