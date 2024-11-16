class Solution {
public:
unordered_map<char, string> mp = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};
    void combi(string &digits,int index,vector<string>&ans,string &s){
        if(index>=digits.size()){
            if(s.size()>0) ans.push_back(s);
            return;
        }

        string currString=mp[digits[index]];
        for(int i=0;i<currString.size();i++){
            char ch=currString[i];
            s.push_back(ch);
            combi(digits,index+1,ans,s);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string s;
        combi(digits,0,ans,s);

        return ans;
    }
};


class Solution {
public:
    void solve(int index,string &op,vector<string>&mp,vector<string>&ans,string &digits){
        if(index>=digits.size()){
            if(op.size()>0)
            ans.push_back(op);
            return;
        }

        int digIndex=digits[index]-'0';
        string s=mp[digIndex];

        for(int i=0;i<s.size();i++){
            op.push_back(s[i]);
            solve(index+1,op,mp,ans,digits);
            op.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>mp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        int index=0;

        string op;

        solve(index,op,mp,ans,digits);

        return ans;
    }
};