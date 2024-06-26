
//MY SOLUTION 
class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        int i=0;

        while(i<path.size()){
            if(path[i]=='/'){
                if(st.empty() || st.top()!="/"){
                    string s(1,path[i]);
                    st.push(s);
                }
                i++;
            }
            else{
                string temp;
                bool alpha=false;
                while(i<path.size() && path[i]!='/'){
                    temp.push_back(path[i]);
                    if(isalpha(path[i])) alpha=true;
                    i++;
                }

                if(alpha || temp.size()>2){
                    st.push(temp);
                }
                else if(temp==".."){
                    st.pop();
                    if(!st.empty()) st.pop();
                }
                else{
                    st.pop();
                }
            }
        }

        if(st.empty() || st.size()==1) return "/";

        if(st.top()=="/") st.pop();

        string ans;

        while(!st.empty()){
            string top=st.top();
            st.pop();
            reverse(top.begin(),top.end());

            ans+=top;
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};




//LAKSHAY BHAIYA'S SOLUTION
 void buildAns(stack<string>&st,string &ans){
            if(st.empty()){
                return;
            }
            string minPath=st.top();st.pop();
            buildAns(st,ans);

            ans+=minPath;
        }
        string simplifyPath(string path) {
        stack<string>st;
        int i=0;

        while(i<path.size()){
            int start=i;
            int end=i+1;

            while(end<path.size() && path[end]!='/'){
                end++;
            }

            string minPath=path.substr(start,end-start);
            i=end;

            if(minPath=="/" || minPath=="/."){
                continue;
            }
            else if(minPath!="/.."){
                st.push(minPath);
            }
            else if(!st.empty()){
                st.pop();
            }
        }

        string ans=st.empty()?"/":"";
        buildAns(st,ans);

        return ans;
    }
