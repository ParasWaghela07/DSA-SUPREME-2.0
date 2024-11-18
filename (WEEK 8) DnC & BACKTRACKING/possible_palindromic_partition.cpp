class Solution {
  public:
    void solve(string &s,int index,vector<string>&path,vector<vector<string>>&ans){
        if(index>=s.size()){
            ans.push_back(path);
            return;
        }
        string str;
        
        for(int i=index;i<s.size();i++){
            str.push_back(s[i]);
            if(isPalindrome(str)){
                path.push_back(str);
                solve(s,i+1,path,ans);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(string &str){
        int i=0;
        int j=str.size()-1;
        
        while(i<j){
            if(str[i]!=str[j]) return false;
            i++;
            j--;
        }
        
        return true;
    }
    vector<vector<string>> allPalindromicPerms(string s) {
        vector<vector<string>>ans;
        vector<string>path;
        solve(s,0,path,ans);
        
        return ans;
    }
};