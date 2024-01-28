class Solution {  //TLE --> DP
public:
    bool solve(string &s,string &p,int si,int pi){
        if(si==s.size() && pi==p.size()){
            return true;
        }
        if(si==s.size() && pi<p.size()){
            while(pi<p.size()){
                if(p[pi]!='*') return false;
                pi++;
            }

            return true;
        }

        if(s[si]==p[pi] || p[pi]=='?'){
            return solve(s,p,si+1,pi+1);
        }

        if(p[pi]=='*'){
            bool case1=solve(s,p,si,pi+1);
            bool case2=solve(s,p,si+1,pi);

            return case1|case2;
        }

        return false;
    }
    bool isMatch(string s, string p) {
        int si=0;
        int pi=0;

        return solve(s,p,si,pi);
    }
};