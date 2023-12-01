
//MY SOLUTION //DONT USE

class Solution {
public:
    string simplifyPath(string path) {
        int i=0;

        stack<char>st;
        while(i<path.size()){

            if(path[i]=='/'){

                if(!st.empty() && st.top()=='/'){
                    i++;
                    continue;
                }
                else{
                    st.push(path[i]);
                }

                i++;

            }
            else if(i-1>=0 && path[i-1]=='/' && path[i]=='.'){

                if(i+2<path.size() && path[i+1]=='.' && path[i+2]=='.'){
                    while(path[i]=='.'){
                        st.push(path[i]);
                        i++;
                    }
                }

                 else if(i-1>=0 && path[i-1]=='/' && i+1<path.size() && path[i+1]=='.'){

                   if(!st.empty()){
                       st.pop();
                   }

                   if(st.empty() && i+2<path.size() && path[i+2]!='/'){
                       st.push('/');
                       st.push('.');
                       st.push('.');
                       i=i+2;
                   }
                   else{

                    while(!st.empty() && st.top()!='/'){
                    st.pop();
                   }

                   i=i+2;

                   }

                   
               }
               else if(i+1<path.size() && path[i+1]>='a' && path[i+1]<='z'){
                   st.push(path[i]);
                   i++;
               }

               else{
                   i++;
               }
            }
            else{
                st.push(path[i]);
                i++;
            }
        }

            while(!st.empty() && st.top()=='/'){
            st.pop();
            }

            if(st.empty()){
                st.push('/');
            }
        


        string ans;

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
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
