class Solution {
public:
    string conv(string s){
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
    bool isIsomorphic(string s, string t) {
        if(conv(s)==conv(t)) return true;
        
        return false;
    }
};