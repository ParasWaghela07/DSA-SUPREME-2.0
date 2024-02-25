class Solution {
public:
    int solve(vector<int>&v,int s,int e){
        if(s==e){
            return v[s];
        }

        int mid=(s+e)/2;
        int leftMaxSum=solve(v,s,mid);
        int rightMaxSum=solve(v,mid+1,e);

        int leftTraverseMax=INT_MIN;
        int rightTraverseMax=INT_MIN;

        int temp1=0;
        for(int i=mid;i>=s;i--){
            temp1+=v[i];
            leftTraverseMax=max(leftTraverseMax,temp1);
        }

        int temp2=0;
        for(int i=mid+1;i<=e;i++){
            temp2+=v[i];
            rightTraverseMax=max(rightTraverseMax,temp2);
        }

        int crossMidSum=leftTraverseMax+rightTraverseMax;

        return max(crossMidSum,max(leftMaxSum,rightMaxSum));
        
    }
    int maxSubArray(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);
    }
};