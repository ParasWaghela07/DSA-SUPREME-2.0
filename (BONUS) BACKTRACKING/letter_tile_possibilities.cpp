class Solution {
public:
    int solve(string &tiles,int index,unordered_map<char,int>&mp){
        if(index>=tiles.size()) return 0;

        int ans=0;
        for(char ch='A';ch<='Z';ch++){
            if(mp[ch]>0){
                ans++;
                mp[ch]--;
                ans+=solve(tiles,index+1,mp);
                mp[ch]++;
            }
        }

        return ans;
    }
    int numTilePossibilities(string tiles) {
        unordered_map<char,int>mp;
        for(auto it:tiles) mp[it]++;

        int ans=solve(tiles,0,mp);

        return ans;
    }
};


class Solution {
public:
    int solve(vector<int>&frq){
        int ans=0;
        for(int i=0;i<26;i++){
            if(frq[i]>0){
                ans++;
                frq[i]--;
                int recursionAns=solve(frq);
                ans+=recursionAns;
                frq[i]++;
            }
        }

        return ans;
    }
    int numTilePossibilities(string tiles) {
        vector<int>frq(26,0);
        for(int i=0;i<tiles.size();i++){
            frq[tiles[i]-'A']++;
        }
        int ans=solve(frq);

        return ans;
    }
};