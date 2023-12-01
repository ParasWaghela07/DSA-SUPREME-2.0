//LINE 25 ERROR , NOT SUBMITTED IN LEETCODE , PB NO:-394


class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        for(auto ch : s){
            string toRepeat="";
            if(ch==']'){
                while(!st.empty() && !isdigit(st.top()[0])){
                    string top=st.top();

                    if(top!="[")
                    toRepeat+=top;

                    st.pop();
                }

                string numeric="";
                while(!st.empty() && isdigit(st.top()[0])){
                    string top=st.top();
                    toRepeat+=top;
                    st.pop();
                }

                reverse(numeric.begin(),numeric.end());
                int n=stoi(numeric);

                string currString="";
                while(n--){
                    currString+=toRepeat;
                }

                st.push(currString);


            }
            else{
                string temp(1,ch);
                st.push(temp);
            }
        }

        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }

        return ans;
    }
};