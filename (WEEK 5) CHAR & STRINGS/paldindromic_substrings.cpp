class Solution {
public:

    int Count(string s,int i,int j){
        int count=0;
        while(i>=0 && j<s.size() && s[i]==s[j]){
            count++;
            i--;
            j++;
        }
        return count;
    }


    int countSubstrings(string s) {
        int totalcount=0;

        for(int i=0;i<s.size();i++){

            int j=i;

            int evencount=Count(s,i,j+1);
            int oddcount=Count(s,i,j);

            totalcount+=evencount+oddcount;

        }
        return totalcount;
    }
};