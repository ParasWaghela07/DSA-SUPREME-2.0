class Solution {
public:
    string convert(string s){
        unordered_map<char,char>mp;
        char c='a';

        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]=c;
                c++;
            }
        }

        string ans;
        for(int i=0;i<s.size();i++){
            ans.push_back(mp[s[i]]);
        }

        return ans;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        string patt=convert(pattern);
        vector<string>ans;

        for(auto it:words){
            if(convert(it)==patt){
                ans.push_back(it);
            }
        }

        return ans;
    }
};