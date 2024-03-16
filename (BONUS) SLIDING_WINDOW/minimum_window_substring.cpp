class Solution {
public:
    string minWindow(string s, string t) {
        int slen=s.size();
        int tlen=t.size();
        int start=0;

        if(tlen>slen){
            return "";
        }

        unordered_map<char,int>smap;
        unordered_map<char,int>tmap;

        int anslen=INT_MAX;
        int ansIndex=-1;

        for(auto it:t){
            tmap[it]++;
        }

        int count=0;
        int i=0;

        while(i<s.size()){
            char ch=s[i];
            smap[ch]++;
            if(tmap.find(ch)!=tmap.end() && smap[ch]<=tmap[ch]){
                count++;
            }
            
            if(count==tlen){
                while(smap[s[start]]>tmap[s[start]] || tmap.find(s[start])==tmap.end()){
                    smap[s[start]]--;
                    start++;
                }

                if(i-start+1<anslen){
                    anslen=i-start+1;
                    ansIndex=start;
                }
            }

            i++;
        }
        if(ansIndex==-1) return "";
        return s.substr(ansIndex,anslen);
    }
};