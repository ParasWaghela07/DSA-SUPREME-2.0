class Solution {
public:
    bool isValid(char &c){
        if(c<65){
            return true;
        }
        if(c>90 && c<97){
            return true;
        }

        return false;
    }
    string reverseOnlyLetters(string s) {
        int i=0;
        int j=s.size()-1;

        while(i<j){
            if(isValid(s[i])){
                i++;
            }
            else if(isValid(s[j])){
                j--;
            }
            else{
                swap(s[i],s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};