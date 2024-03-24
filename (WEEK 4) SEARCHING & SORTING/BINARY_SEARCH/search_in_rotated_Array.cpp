class Solution {
public:
    int findPivot(vector<int>&nums){
        int s=0;
        int e=nums.size()-1;

        while(s<=e){
            if(s==e) return s;

            int mid=s+(e-s)/2;

            if(mid+1<nums.size() && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(mid-1>=0 && nums[mid]<nums[mid-1]){
                return mid-1;
            }
            else if(nums[mid]<nums[0]){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }

        return -1;
    }
    int binarySearch(int s,int e,vector<int>&nums,int target){

        while(s<=e){
            int mid=s+(e-s)/2;

            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>=target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }

        return -1;
    }
    int search(vector<int>& nums, int target) {
        int pivot=findPivot(nums);
        if(target >= nums[0] && target<=nums[pivot]){
            return binarySearch(0,pivot,nums,target);
        }        
        return binarySearch(pivot+1,nums.size()-1,nums,target);
    }
};