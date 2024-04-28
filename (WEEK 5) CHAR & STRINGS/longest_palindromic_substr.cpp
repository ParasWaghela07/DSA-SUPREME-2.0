class Solution {
public:
    bool isValid(string &s,int i,int j){
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string ans;

        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(isValid(s,i,j)){
                    string temp=s.substr(i,j-i+1);
                    if(temp.size() > ans.size()){
                        ans=temp;
                    }
                }
            }
        }

        return ans;
    }
};


//OPTIMIZED

class Solution {
public:
    string solve(string &s,int i,int j){
        while(i>=0 && j<s.size() && s[i]==s[j]){
            i--;
            j++;
        }

        return s.substr(i+1,j-i-1);
    }
    string longestPalindrome(string s) {
        string ans;
        for(int i=0;i<s.size();i++){
            
            string odd=solve(s,i,i);
            string even=solve(s,i,i+1);

            if(odd.size()>ans.size()){
                ans=odd;
            }
            if(even.size()>ans.size()){
                ans=even;
            }
        }

        return ans;
    }
};