class Solution {
public:
    // string reorganizeString(string s) {
    //     int map[26]={0};

    //     for(int i=0;i<s.size();i++){
    //         map[s[i]-'a']++;           //converting 97-122 range elements in 0-25
    //     }

    //     char max_freq_char;
    //     int max_freq=INT_MIN;

    //     for(int i=0;i<26;i++){
    //         if(map[i]>max_freq){
    //             max_freq=map[i];
    //             max_freq_char=i+'a';
    //         }
    //     }

    //     int index=0;
    //     while(max_freq>0 && index<s.size()){
    //         s[index]= max_freq_char;
    //         max_freq--;
    //         index+=2;
    //     }

    //     if(max_freq!=0){
    //         return "";
    //     }

    //     map[max_freq_char-'a']=0;

    //     for(int i=0;i<26;i++){
    //         while(map[i]>0){
    //             if(index>=s.size()){
    //                 index=1;
    //             }
    //             s[index]=i+'a';
    //             map[i]--;
    //             index+=2;
    //         }
    //     }

    //     return s;


    // }
    class info{
        public:
        char val;
        int count;

        info(char ch,int cnt){
            this->val=ch;
            this->count=cnt;
        }
    };

    class compare{
        public:
        bool operator()(info a,info b){
            return a.count < b.count;
        }
    };

    string reorganizeString (string s){
        priority_queue<info,vector<info>,compare>pq;
        string ans="";

        int map[26]={0};

        for(int i=0;i<s.size();i++){
            map[s[i]-'a']++;
        }

        for(int i=0;i<26;i++){
            if(map[i]>0){
                info temp(i+'a',map[i]);
                pq.push(temp);
            }
        }

        while(pq.size()>1){
            info first=pq.top(); pq.pop();
            info second=pq.top();pq.pop();

            ans+=first.val;
            first.count--;
            ans+=second.val;
            second.count--;

            if(first.count>0){
                pq.push(first);
            }
            if(second.count>0){
                pq.push(second);
            }
        }

        if(pq.size()==1){
            info temp=pq.top();
            pq.pop();

            ans+=temp.val;
            temp.count--;

            if(temp.count>0){
                return "";
            }
        }

        return ans;
    }
};