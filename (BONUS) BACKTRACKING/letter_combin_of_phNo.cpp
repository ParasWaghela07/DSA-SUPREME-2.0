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