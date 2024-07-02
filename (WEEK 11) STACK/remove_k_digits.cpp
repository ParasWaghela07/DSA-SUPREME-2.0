class Solution {
public:
    string removeKdigits(string num, int k) {

        if(k>=num.size()) return "0";

        stack<int>st;

        st.push(num[0]-'0');
        int i=1;

        while(i<num.size()){
            int curr=num[i]-'0';

            while(!st.empty() && st.top()>curr && k>0){
                st.pop();
                k--;
            }

            st.push(curr);
            i++;
        }

        while(k){
            st.pop();
            k--;
        }

        string ans;

        while(!st.empty()){
            ans.push_back(st.top()+'0');
            st.pop();
        }

        while(ans.size()>0 && ans.back()=='0') ans.pop_back();

        if(ans.size()==0) return "0";

        reverse(ans.begin(),ans.end());

        return ans;
    }
};