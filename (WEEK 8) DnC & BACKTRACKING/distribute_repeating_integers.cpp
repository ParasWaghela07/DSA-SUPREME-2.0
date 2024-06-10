class Solution {
public:

    //mine
    class Solution {
public:
    
    bool prmt(vector<int>&quantity,int index,unordered_map<int,int>&mp){
        if(index>=quantity.size()){
            return true;
        }

        int need=quantity[index];

        for(auto &it:mp){
            if(it.second >= need ){
                it.second=it.second-need;
                if(prmt(quantity,index+1,mp)){
                    return true;
                }
                else
                it.second=it.second+need;
            }
        }

        return false;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
        sort(quantity.rbegin(),quantity.rend());

        return prmt(quantity,0,mp);
    }
};

//lakshay bhaiya
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