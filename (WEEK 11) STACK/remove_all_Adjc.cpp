class Solution {
public:
    string removeDuplicates(string s) {
        string ans="";
        int index=0
        ;

        while(index<s.size()){
            if(ans.size()>0 && s[index]==ans[ans.size()-1]){
                ans.pop_back();
            }
            else{
                ans.push_back(s[index]);
            }
            index++;
        }
        return ans;

        // stack<char>st;

        // for(int i=0;i<s.size();i++){
        //     if(!st.empty() && s[i]==st.top()){
        //         st.pop();
        //     }
        //     else{
        //         st.push(s[i]);
        //     }
        // }

        // string ans;

        // while(!st.empty()){
        //     ans.push_back(st.top());
        //     st.pop();
        // }

        // reverse(ans.begin(),ans.end());

        // return ans;
    }
};