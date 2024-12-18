
--APPROACH-1

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int>st;
        vector<int>ans=prices;

        for(int i=0;i<prices.size();i++){
            while(!st.empty() && prices[i]<=prices[st.top()]){
                ans[st.top()]-=prices[i];
                st.pop();
            }

            st.push(i);
        }

        return ans;
    }
};

--APPROACH-2

class Solution {
public:
    vector<int> nextSmaller(vector<int>&nums){
        stack<int>st;
        st.push(0);
        vector<int>ans(nums.size());
        for(int i=nums.size()-1;i>=0;i--){
            while(nums[i]<st.top()){
                st.pop();
            }

            ans[i]=st.top();
            st.push(nums[i]);
        }

        return ans;
    }
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>nextsm=nextSmaller(prices);
        vector<int>ans=prices;

        for(int i=0;i<ans.size();i++){
            ans[i]=ans[i]-nextsm[i];
        }

        return ans;
    }
};


