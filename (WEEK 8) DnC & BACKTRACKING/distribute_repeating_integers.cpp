class Solution {
public:
    bool solve(vector<int>&frq,vector<int>&q,int order){
        if(order>=q.size()){
            return true;
        }

        for(int i=0;i<frq.size();i++){
            int custWant=q[order];
            if(frq[i] >= custWant){
                frq[i]=frq[i]-custWant;
                if(solve(frq,q,order+1)){
                    return true;
                }
                else{
                    frq[i]=frq[i]+custWant;
                }
            }
        }

        return false;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
         unordered_map<int,int>mp;
         for(int i=0;i<nums.size();i++){
             mp[nums[i]]++;
         }
         vector<int>frq;
         for(auto it:mp){
             frq.push_back(it.second);
         }
         sort(quantity.rbegin(),quantity.rend());//to reduce time/comparisons
         return solve(frq,quantity,0);
    }
};