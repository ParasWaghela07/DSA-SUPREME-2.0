class Solution {
    public:
        bool isVowel(char &ch){
            return ch=='a' || ch=='e' || ch=='i'||ch=='o'||ch=='u';
        }
        long long countOfSubstrings(string word, int k) {
            unordered_map<char,int>mp;
            int n=word.size();
            vector<int>nextcons(n);
            int idx=n;
    
            for(int i=n-1;i>=0;i--){
                nextcons[i]=idx;
                if(!isVowel(word[i])) idx=i;
            }
    
            long long ans=0;
            int i=0;
            int j=0;
            int cons=0;
    
            while(j<n){
                if(isVowel(word[j])) mp[word[j]]++;
                else cons++;
    
                while(i<n && cons>k){
                    if(isVowel(word[i])){
                        mp[word[i]]--;
                        if(mp[word[i]]==0) mp.erase(word[i]);
                    }
                    else cons--;
                    i++;
                }
    
                while(i<n && mp.size()==5 && cons==k){
                    ans+=nextcons[j]-j;
                    if(isVowel(word[i])){
                        mp[word[i]]--;
                        if(mp[word[i]]==0) mp.erase(word[i]);
                    }
                    else cons--;
                    i++;
                }
    
                j++;
            }
    
            return ans;
        }
    };