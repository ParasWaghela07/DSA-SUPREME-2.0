class Solution {
  public:
    vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
        vector<int>ans;
        deque<int>dq;
        
        for(int i=0;i<k;i++){
            if(arr[i]<0) dq.push_back(i);
        }
        
        if(dq.empty()) ans.push_back(0);
        else ans.push_back(arr[dq.front()]);
        
        for(int i=k;i<arr.size();i++){
            if(arr[i]<0) dq.push_back(i);
            
            if(!dq.empty() && dq.front()<i-k+1) dq.pop_front();
            
            if(dq.empty()) ans.push_back(0);
            else ans.push_back(arr[dq.front()]);
        }
        
        return ans;
    }
};