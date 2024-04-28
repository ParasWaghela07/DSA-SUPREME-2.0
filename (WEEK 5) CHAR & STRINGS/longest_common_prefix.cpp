class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int index=0;
        string s=strs[0];
        string ans;
        
        for(int i=0;i<s.size();i++){
            char c=s[i];
            for(auto j:strs){
                if(j[index]!=c) return ans;
            }
            ans.push_back(c);
            index++;
        }

        return ans;
    }
};


//LAKSHAY BHAIYA
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int i=0;

        while(1){
            char char_curr=0;
            for(auto s:strs){
                if(i>=s.size()){
                    char_curr=0;
                    break;
                }

                if(char_curr==0){
                    char_curr=s[i];
                }
                else if(s[i]!=char_curr){
                    char_curr=0;
                    break;
                }
            }
            if(char_curr==0) break;
            ans.push_back(char_curr);
            i++;
        }

        return ans;
    }
};