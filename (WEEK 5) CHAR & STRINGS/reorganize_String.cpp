MINEEEEEEEEEE

class Solution {
public:
    class compare{
        public:
        bool operator()(auto &a,auto &b){
            return a.second < b.second;
        }
    };
    string reorganizeString(string s) {
        unordered_map<char,int>mp;
        for(auto it:s){
            mp[it]++;
        }

        priority_queue<pair<char,int>,vector<pair<char,int>>,compare>pq;

        for(auto it:mp){
            pq.push({it.first,it.second});
        }

        int i=0;
        vector<char>v(s.size(),'-');
        
            char a=pq.top().first;
            int b=pq.top().second;
            pq.pop();

            while(i<v.size()){
                if(v[i]=='-'){
                    v[i]=a;
                    b--;
                    i=i+2;
                }
                if(b==0) break;
            }

            if(b>0) return "";
            if(i>=v.size()) i=1;
        
        while(!pq.empty()){
            char c=pq.top().first;
            int frq=pq.top().second;
            pq.pop();

            while(i<v.size()){
                if(v[i]=='-'){
                    cout<<c<<" ";
                    v[i]=c;
                    frq--;
                    i=i+2;
                    if(i>=v.size()){
                        i=1;
                    }
                }
                if(frq==0) break;
            }
            cout<<endl;

            if(frq>0) return "";
        }

        string ans;
        for(auto it:v){
            ans.push_back(it);
        }

        return ans;
    }
};





string week method
class Solution {
public:
    string reorganizeString(string s) {
        int map[26]={0};

        for(int i=0;i<s.size();i++){
            map[s[i]-'a']++;           //converting 97-122 range elements in 0-25
        }

        char max_freq_char;
        int max_freq=INT_MIN;

        for(int i=0;i<26;i++){
            if(map[i]>max_freq){
                max_freq=map[i];
                max_freq_char=i+'a';
            }
        }

        int index=0;
        while(max_freq>0 && index<s.size()){
            s[index]= max_freq_char;
            max_freq--;
            index+=2;
        }

        if(max_freq!=0){
            return "";
        }

        map[max_freq_char-'a']=0;

        for(int i=0;i<26;i++){
            while(map[i]>0){
                if(index>=s.size()){
                    index=1;
                }
                s[index]=i+'a';
                map[i]--;
                index+=2;
            }
        }

        return s;


    }
};