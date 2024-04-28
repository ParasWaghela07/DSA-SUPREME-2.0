class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();

        vector<int>left(n,0);
        vector<int>right(n,0);

        int leftMax=height[0];
        for(int i=1;i<n-1;i++){
            if(height[i]<leftMax){
                left[i]=leftMax;
            }
            leftMax=max(leftMax,height[i]);
        }

        int rightMax=height[n-1];
        for(int i=n-1;i>0;i--){
            if(height[i]<rightMax){
                right[i]=rightMax;
            }
            rightMax=max(rightMax,height[i]);
        }

        int ans=0;

        for(int i=1;i<n-1;i++){
            if(left[i]==0 || right[i]==0){
                continue;
            }

            ans += min(left[i],right[i])-height[i];
        }

        return ans;

    }
};