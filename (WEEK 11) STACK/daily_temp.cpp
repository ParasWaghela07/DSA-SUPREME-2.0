class Solution {
public:
-------------METHOD 1------------
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>ans(temperatures.size());
        stack<int>st;
        for(int i=temperatures.size()-1;i>=0;i--){
            int curr=temperatures[i];
            while(!st.empty() && temperatures[st.top()]<=curr){
                st.pop();
            }

            if(st.empty()) ans[i]=0;
            else ans[i]=st.top()-i;

            st.push(i);
        }

        return ans;
    }
};

------------METHOD 2------------
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>ans(temperatures.size());
        stack<int>st;
        for(int i=0;i<temperatures.size();i++){
            int curr=temperatures[i];
            while(!st.empty() && temperatures[st.top()]<curr){
                ans[st.top()]=i-st.top();
                st.pop();
            }

            st.push(i);
        }

        return ans;
    }
};