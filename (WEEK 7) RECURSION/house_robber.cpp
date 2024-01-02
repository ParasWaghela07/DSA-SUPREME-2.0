class Solution {
public:
    int solve(vector<int>& nums,int size,int index){ //////////////// DYNAMIC PROGRAMMING QST , NOT SUBMITTED IN LEETCODE
        if(index>=size){
            return 0;
        }

        //current index pe chori mat kro
        int op1=solve(nums,size,index+1);

        //current index pe chori karlo
        int op2=nums[index] + solve(nums,size,index+2);

        int final=max(op1,op2);

        return final;
    }
    int rob(vector<int>& nums) {
        int size=nums.size();
        int index=0;

        int ans=solve(nums,size,index);
        return ans;

    }
};