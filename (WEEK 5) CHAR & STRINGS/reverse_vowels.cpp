class Solution {
public:
    bool isVowel(char c){
        c=tolower(c);
        if(c=='a') return true;
        if(c=='e') return true;
        if(c=='i') return true;
        if(c=='o') return true;
        if(c=='u') return true;

        return false;
    }
    string reverseVowels(string s) {
        int i=0;
        int j=s.size()-1;

        while(i<j){
            while(i<j && !isVowel(s[i])){
                i++;
            }
            while(j>i && !isVowel(s[j])){
                j--;
            }
            if(i<j){
                swap(s[i],s[j]);
                i++;
                j--;
            }
        }

        return s;
    }
};