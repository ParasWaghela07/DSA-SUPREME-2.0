class Solution {
public:
    --brute force--TLE----(K*NLOGN)--
    long long maxKelements(vector<int>& nums, int k) {
        long long ans=0;
        while(k--){--(K*NLOGN)--
            sort(nums.begin(),nums.end());
            ans+=nums.back();

            int back=nums.back();
            nums.pop_back();

            int num=back%3==0 ? back/3 : (back/3)+1;
            nums.push_back(num);
        }

        return ans;
    }
};
--OPTIMAL--(KLOGN)--
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans=0;
        priority_queue<int>pq;
        for(auto it:nums) pq.push(it);--O(NLOGN)--

        while(k--){--O(KLOGN)
            int top=pq.top();
            pq.pop();--O(LOGN)--

            ans+=top;

            int num=top%3==0 ? top/3 : top/3 + 1;
            pq.push(num);--O(LOGN)--
        }

        return ans;
    }
};