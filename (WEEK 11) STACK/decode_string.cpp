class Solution {
public:
    string decodeString(string s) {
         stack<string>st;

         for(int i=0;i<s.size();i++){
            if(s[i]==']'){
                string toRepeat="";
                while(!st.empty() && st.top()!="["){
                    toRepeat+=st.top();
                    st.pop();
                }
                st.pop();

                string numeric="";
                while(!st.empty() && isdigit(st.top()[0])){
                    numeric+=st.top();
                    st.pop();
                }

                reverse(numeric.begin(),numeric.end());

                int n=stoi(numeric);
                string final="";
                while(n){
                    final+=toRepeat;
                    n--;
                }

                st.push(final);

            }
            else{
               string temp(1,s[i]);
               st.push(temp);
            }
         }

         string ans="";
         while(!st.empty()){
            ans+=st.top();
            st.pop();
         }

         reverse(ans.begin(),ans.end());

         return ans;
    }
};