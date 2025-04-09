class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            int sum1=nums[0];
            int maxi=nums[0];
    
            int mini=nums[0];
            int sum2=nums[0];
    
            
    
            for(int i=1;i<nums.size();i++){
                sum1=max(sum1+nums[i],nums[i]);
                maxi=max(maxi,sum1);
    
                sum2=min(sum2+nums[i],nums[i]);
                mini=min(mini,sum2);
            }
    
            return max(abs(maxi),abs(mini));
    
        }
    };

class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            int sum=nums[0];
            int maxi=nums[0];
            
    
            for(int i=1;i<nums.size();i++){
                sum=max(sum+nums[i],nums[i]);
                maxi=max(maxi,sum);
            }
    
            int mini=nums[0];
            sum=nums[0];
    
            for(int i=1;i<nums.size();i++){
                sum=min(sum+nums[i],nums[i]);
                mini=min(mini,sum);
            }
    
            return max(abs(maxi),abs(mini));
    
        }
    };