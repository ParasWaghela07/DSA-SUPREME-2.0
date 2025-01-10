class Solution {
public:
    --LEETCODE-30 // BRUTE
    bool isValid(int index,string &s,unordered_map<string,int>mp,int k,int winSize){
        for(int i=index;i<index+winSize;i+=k){
            string w=s.substr(i,k);
            if(mp.find(w) != mp.end()) {
                if(--mp[w] == -1) {
                    return false;
                }
            } else {
                return false;
            }
        }

        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int>mp;
        for(auto it:words) mp[it]++;

        int k=words[0].size();
        int winSize=words.size()*k;

        vector<int>ans;
        for(int i=0;i+winSize<=s.size();i++){
            if(isValid(i,s,mp,k,winSize)) ans.push_back(i);
        }

        return ans;
    }
};