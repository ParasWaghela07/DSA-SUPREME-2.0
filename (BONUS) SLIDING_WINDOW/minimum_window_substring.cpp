class Solution {
public:


    ---OWN----
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        for(auto it:t)mp[it]++;

        int count=t.size();

        int i=0;
        int j=0;

        int ansi=-1;
        int ansj=-1;

        while(j<s.size()){
            char ch=s[j];
            if(mp.find(ch)!=mp.end()){
                mp[ch]--;
                if(mp[ch]>=0){
                    count--;
                }
            }

            while(i<=j && count==0){
                cout<<i<<","<<j<<endl;
                if(ansi==-1 && ansj==-1) {
                    ansi=i;
                    ansj=j;
                }
                else if(j-i < ansj-ansi){
                    ansi=i;
                    ansj=j;
                }

                char c=s[i];
                if(mp.find(c)!=mp.end()){
                    if(mp[c]==0)count++;
                    mp[c]++;
                }
                i++;
            }
            j++;
        }

        if(ansi==-1 && ansj==-1) return "";

        return s.substr(ansi,ansj-ansi+1);
    }
};


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