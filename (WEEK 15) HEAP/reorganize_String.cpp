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
    class Solution {
public:
    class compare{
        public:
        bool operator()(const pair<char,int>&a,const pair<char,int>&b){
            return a.second<b.second;
        }
    };
    string reorganizeString(string s) {
        priority_queue<pair<char,int>,vector<pair<char,int>>,compare>pq;
        unordered_map<char,int>mp;

        for(auto it:s){
            mp[it]++;
        }

        for(auto it:mp){
            pq.push({it.first,it.second});
        }

        string ans="";

        while(pq.size()>1){
            auto top1=pq.top();pq.pop();
            auto top2=pq.top();pq.pop();

            ans.push_back(top1.first);
            ans.push_back(top2.first);

            top1.second--;
            top2.second--;

            if(top1.second>0) pq.push(top1);
            if(top2.second>0) pq.push(top2);
        }

        if(!pq.empty()){
            auto top1=pq.top();pq.pop();
            if(top1.second>1) return "";
            if(ans.size()>1 && top1.first==ans.back()) return "";
            ans.push_back(top1.first);
        }
            return ans;
    }
};

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