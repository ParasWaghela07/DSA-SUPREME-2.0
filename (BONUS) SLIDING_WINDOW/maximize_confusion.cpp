class Solution {
public:
    //BRUTE-FORCE O(N*2^N)
    int ans=1;

    void check(string &s){
        int len=1;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]) len++;
            else len=1;

            ans=max(ans,len);
        }
    }
    void solve(string &s,int k,int index){
        if(index>=s.size() || k==0) {
            check(s);
            return;
        }

        s[index]=s[index]=='T' ? 'F' :'T';
        solve(s,k-1,index+1);

        s[index]=s[index]=='T' ? 'F' :'T';
        solve(s,k,index+1);
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        solve(answerKey,k,0);
        return ans;
    }
};

//DOUBLE PASS - O(N)
class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int ans=1;
        int i=0;
        int j=0;
        int cnt=k;

        while(j<s.size()){
            if(s[j]=='F') cnt--;

            while(cnt<0){
                if(s[i]=='F') cnt++;
                i++;
            }

            ans=max(ans,j-i+1);
            j++;
        }

        cnt=k;
        i=0;
        j=0;
        while(j<s.size()){
            if(s[j]=='T') cnt--;

            while(cnt<0){
                if(s[i]=='T') cnt++;
                i++;
            }

            ans=max(ans,j-i+1);
            j++;
        }

        return ans;
    }
};

//SINGLE PASS - O(N)
class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int ans=1;
        int i=0;
        int j=0;
        int cnt=k;

        int Ts=0;
        int Fs=0;

        while(j<s.size()){
            if(s[j]=='T') Ts++;
            else Fs++;

            while(min(Ts,Fs)>k){
                if(s[i]=='T') Ts--;
                else Fs--;
                i++;
            }

            ans=max(ans,j-i+1);
            j++;
        }

        return ans;
    }
};