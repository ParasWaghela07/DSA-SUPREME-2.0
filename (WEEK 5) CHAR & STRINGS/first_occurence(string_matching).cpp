
NAIVE APPROACH

class Solution {
public:
    bool matched(string &haystack,int i,string &needle){
        for(int j=0;j<needle.size();j++){
            if(i>=haystack.size()) return false;
            if(needle[j]!=haystack[i]) return false;
            i++;
        }

        return true;
    }
    int strStr(string haystack, string needle) {
        for(int i=0;i<haystack.size();i++){
            if(haystack[i]==needle[0] && matched(haystack,i,needle)){
                return i;
            }
        }

        return -1;
    }
};


LAKSHAY BHAIYA
class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0;i<haystack.size();i++){
            for(int j=0;j<needle.size();j++){
                if(haystack[i+j]!=needle[j]){
                    break;
                }
                if(j==needle.size()-1) return i;
            }
        }

        return -1;
    }
};

