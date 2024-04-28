class Solution {
public:
    bool check(int i,int k,string &ans,char &c){
        while(k-1){
            if(i<0) return false;
            if(ans[i]==c){
                i--;
                k--;
            }
            else return false;
        }

        return true;
    }
    string removeDuplicates(string s, int k) {
        string ans;
        for(int i=0;i<s.size();i++){
            if(ans.size()>0 && ans[ans.size()-1]==s[i]){
                if(check(ans.size()-1,k,ans,s[i])){
                    for(int it=k;it>1;it--){
                        ans.pop_back();
                    }
                }
                else{
                    ans.push_back(s[i]);
                }
            }
            else{
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};

OPTIMIZED

class Solution {
public:
    string removeDuplicates(string s, int k) {
        int i=0;
        int j=0;
        vector<int>count(s.size());

        while(j<s.size()){
            s[i]=s[j];
            count[i]=1;

            if(i-1>=0 && s[i]==s[i-1]){
                count[i]+=count[i-1];
            }

            if(count[i]==k){
                i=i-k;
            }

            i++;
            j++;
        }

        return s.substr(0,i);
    }
};