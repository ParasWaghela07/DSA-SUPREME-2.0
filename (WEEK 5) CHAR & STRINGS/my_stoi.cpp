class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int sign=1;
        long ans=0;

        while(i<s.size() && s[i]==' '){
            i++;
        }

        if(i<s.size() && s[i]=='-'){
            sign=-1;
            i++;
        }
        else if(i<s.size() && s[i]=='+'){
            i++;
        }

        // while(i<s.size() && s[i]=='0'){
        //     i++;
        // }

        while(i<s.size() && isdigit(s[i])){
                ans=(ans*10)+(s[i]-'0');
                if(ans>=2147483648 && sign==1) return 2147483647;
                if(ans>=2147483648 && sign==-1) return -2147483648;
                i++;
        }

        return ans*sign;

    }
};