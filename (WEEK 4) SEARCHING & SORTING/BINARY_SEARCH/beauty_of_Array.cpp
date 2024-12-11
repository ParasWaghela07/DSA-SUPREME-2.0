class Solution {
public:
    --LEETCODE 2779---  
 --OPTIMIZED--
    class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0;
        int ans=0;

        for(int j=0;j<nums.size();j++){
            if(nums[j]-nums[i]>2*k) i++;
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};


    int bs(vector<vector<int>>&ranges,int index){
        int s=0;
        int e=index;

        int currStart=ranges[index][0];
        
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            int prevEnd=ranges[mid][1];

            if(currStart<=prevEnd){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }

        return ans;
    }
    int maximumBeauty(vector<int>& nums, int k) {
        vector<vector<int>>ranges;
        for(auto it:nums) ranges.push_back({it-k,it+k});

        sort(ranges.begin(),ranges.end());
        int ans=0;

        int l=INT_MIN;
        int r=INT_MAX;
        int temp=0;

        for(int i=0;i<ranges.size();i++){
            vector<int>it=ranges[i];

            int currL=it[0];
            int currR=it[1];

            if(currL<=r){
                temp++;
                l=max(l,currL);
                r=min(r,currR);
            }
            else{
                int index=bs(ranges,i);
                temp=i-index+1;

                l=currL;
                r=min(currR,ranges[index][1]);
            }
            ans=max(ans,temp);
        }
        return ans;
    }
};


class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<vector<int>>ranges;
        for(auto it:nums) ranges.push_back({it-k,it+k});

        sort(ranges.begin(),ranges.end());
        queue<int>q;
        int ans=0;

        for(auto it:ranges){
            while(!q.empty() && q.front()<it[0]) q.pop();

            q.push(it[1]);

            ans=max(ans,(int)q.size());
        }

        return ans;
    }
};

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=0;

        for(int i=0;i<nums.size();i++){
            // (y-x)<=2k
            int x=nums[i];
            int y=x+(2*k);

            int index=upper_bound(nums.begin(),nums.end(),y)-nums.begin(); //it gives just bada
            ans=max(ans,index-i);
        }
        return ans;
    }
};