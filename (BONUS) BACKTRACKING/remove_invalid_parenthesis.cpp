class Solution {
public:
    void solve(int index,string &s,int open,int close,int bal,unordered_set<string>&ans,string &op){
        if(index>=s.size()){
            if(open==0 && close==0 && bal==0)
            ans.insert(op);
            return;
        }

        if(s[index]!='(' && s[index]!=')'){
            op.push_back(s[index]);
            solve(index+1,s,open,close,bal,ans,op);
            op.pop_back();
        }
        else if(s[index]=='('){
            //ignore or delete
            if(open>0)
            solve(index+1,s,open-1,close,bal,ans,op);

            //include
            op.push_back(s[index]);
            solve(index+1,s,open,close,bal+1,ans,op);
            op.pop_back();
        }
        else{
            //ignore or delete
            if(close>0)
            solve(index+1,s,open,close-1,bal,ans,op);

            //include
            if(bal>0){
                op.push_back(s[index]);
                solve(index+1,s,open,close,bal-1,ans,op);
                op.pop_back();
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string>ans;
        int invalidOpen=0;
        int invalidClose=0;
        int balance=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                invalidOpen++;
            }
            else if(s[i]==')'){
                if(invalidOpen>0){
                    invalidOpen--;
                }
                else{
                    invalidClose++;
                }
            }
        }
        string op="";
        int index=0;
        solve(index,s,invalidOpen,invalidClose,balance,ans,op);

        return vector<string>(ans.begin(),ans.end());
    }
};