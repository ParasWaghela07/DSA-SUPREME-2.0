//MY SOLUTION

class Solution {
public:
    bool isValid(string s) {
        if(s[0]!='a'){
            return false;
        }
        stack<char>st;
        
        for(auto ch : s){

            if(ch=='a'){
                st.push(ch);
            }
            else if(ch=='b'){

                if(!st.empty() && st.top()=='a'){
                    st.push(ch);
                }
                else{
                    return false;
                }

            }

            else{

                if(!st.empty() && st.top()=='b'){
                    st.pop();
                }
                else{
                    return false;
                }

                if(!st.empty() && st.top()=='a'){
                    st.pop();
                }
                else{
                    return false;
                }

            }
        }

        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};

//WITHOUT STACK

 while(s.find("abc")!= std::string::npos){
            s.erase(s.find("abc"),3);
        }

        if(s.size()==0){
            return true;
        }
        else{
            return false;
        }

//LAKSHAY BHAIYA'S SOLUTION

//RECURSION
 if(s.size()==0){
            return true;
        }
        int fnd=s.find("abc");
        if(fnd != string::npos){
            string tleft=s.substr(0,fnd);
            string tright=s.substr(fnd + 3,s.size());

            return isValid(tleft+tright);
        }
        return false;
    }

    //STACK

class Solution {
public:
    bool valid(stack<char>st){
        if(st.top()!='b') return false;
        st.pop();
        if(st.top()!='a') return false;

        return true;
    }
    bool isValid(string s) {
        stack<char>st;

        for(int i=0;i<s.size();i++){
            if(s[i]=='c' && st.size()>=2 && valid(st)){
                st.pop();
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }

        if(!st.empty()) return false;
        
        return true;
    }
};


