class Solution {
public:
    -sweep line--> prefix sum--time_complexity=O(n)
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int>pre(s.size()+1,0);
        for(auto it:shifts){
            int s=it[0];
            int e=it[1];
            int dir=it[2]==0 ? -1 : 1 ;

            pre[s]=pre[s]+dir;
            pre[e+1]=pre[e+1]-dir;
        }

        int sum=0;
        for(int i=0;i<s.size();i++){
            sum+=pre[i];
            int shift=(s[i]-'a'+sum)%26;
            if(shift<0){
                shift+=26;
            }
            s[i]=shift+'a';
        }

        return s;
    }
};


class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        for(auto it:shifts){
            int start=it[0];
            int end=it[1];
            int dir=it[2]==0 ?-1:1;

            if(start>end) swap(start,end);

            for(int i=start;i<=end;i++){
                if(s[i]=='a' && dir==-1) s[i]='z';
                else if(s[i]=='z' && dir==1)s[i]='a';
                else s[i]=s[i]+dir;
            }
        }

        return s;
    }
};

