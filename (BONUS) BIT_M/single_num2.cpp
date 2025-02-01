class Solution {
public:
    int getBit(int x,int bit){
        return x&(1<<bit);
    }
    void setBit(int &x,int bit){
        x=x|(1<<bit);
    }
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int bit=0;bit<=31;bit++){
            int ones=0;
            for(auto num:nums){
                if(getBit(num,bit)!=0) ones++;
            }
            if(ones%3!=0) setBit(ans,bit);
        }

        return ans;
    }
};