class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int,int>>q;
        q.push({start,0});
        
        unordered_map<int,bool>mp;
        mp[start]=true;
        
        while(!q.empty()){
            auto front=q.front();
            
            int num=front.first;
            int steps=front.second;
            
            q.pop();
            
            if(num==end) return steps;
          
            for(auto it:arr){
                int newNum=(it*num)%100000;
                
                if(mp[newNum]==false){
                    q.push({newNum,steps+1});
                    mp[newNum]=true;
                }
            }
        }
        
        return -1;
        
        queue<int>q;
        int mod=100000;
        vector<int>ans(100000,-1);
        
        ans[start]=0;
        q.push(start);
        
        while(!q.empty()){
            int front=q.front();
            q.pop();
            
            if(front==end) return ans[front];
            
            for(auto it:arr){
                int newNum=(it*front)%mod;
                if(ans[newNum]==-1){
                    ans[newNum]=ans[front]+1;
                    q.push(newNum);
                }
            }
        }
        
        return -1;
    }
};