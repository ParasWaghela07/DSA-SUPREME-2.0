class Solution {
public:
    bool checkPalin(string &s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
    bool validPalindrome(string s) {
        int i=0;
        int j=s.size()-1;

        while(i<=j){
            if(s[i]!=s[j]){
                bool ans1=checkPalin(s,i+1,j);
                bool ans2=checkPalin(s,i,j-1);

                return ans1|ans2;
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }
};