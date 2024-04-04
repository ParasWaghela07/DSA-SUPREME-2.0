class Solution {
public:
    void solve(string &s, string &part){
        if(s.find(part)==string::npos){
            return;
        }
        else{
            int index=s.find(part);
            s = s.substr(0,index) + s.substr(index + part.size() , s.size());
            solve(s,part);
        }
    }
    string removeOccurrences(string s, string part) {
        // while(s.find(part)!=string::npos){
        //     s.erase(s.find(part),part.size());
        // }
        // return s;
        solve(s,part);
        return s;
    }
};