class Solution {
public:
    --O(2N)--O(1)
    bool canBeValid(string s, string locked) {
        if(s.size()&1) return false;

        int open=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') open++;
            else{
                if(locked[i]=='0') open++;
                else open--;
            }

            if(open<0) return false;
        }

        int close=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==')') close++;
            else{
                if(locked[i]=='0') close++;
                else close--;
            }

            if(close<0) return false;
        }
        return true;
    }
};

--O(2N)--O(2N)
class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size()&1) return false;
        stack<int>st1,st2;
        for(int i=0;i<s.size();i++){
            if(locked[i]=='0'){
                st2.push(i);
            }
            else{
                if(s[i]=='(') st1.push(i);
                else {
                    if(!st1.empty()) st1.pop();
                    else if(!st2.empty()) st2.pop();
                    else return false;
                }
            }
        }

        while(!st1.empty() && !st2.empty() && st1.top() < st2.top()){
            st1.pop();
            st2.pop();
        }

        return st1.empty();
    }
};