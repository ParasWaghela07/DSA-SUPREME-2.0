Given an array arr[] of positive integers, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are m students, the task is to distribute chocolate packets among m students such that -
      i. Each student gets exactly one packet.
     ii. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum and return that minimum possible difference.    
    
    
    
    
    
    int findMinDiff(vector<int>& a, int m) {
        sort(a.begin(),a.end());
        int i=0;
        int j=m-1;
        
        int ans=INT_MAX;
        
        while(j<a.size()){
            ans=min(ans,a[j]-a[i]);
            j++;
            i++;
        }
        
        return ans;
    }