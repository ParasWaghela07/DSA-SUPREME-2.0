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