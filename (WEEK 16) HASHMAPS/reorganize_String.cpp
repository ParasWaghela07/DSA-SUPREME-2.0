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






class Info{
    public:
        char val;
        int count;
    Info(char ch, int cnt) {
        this->val = ch;
        this->count = cnt;
    }
};

class compare{
    public:
        bool operator()(Info a, Info b) {
            return a.count < b.count;
        }
};


class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> freq;
        //int freq[26] = {0};

        //count freq of all chartacter in string
        for(int i=0; i<s.length(); i++) {
            char ch = s[i];
            freq[ch]++;
        }
        //push all characters in maxHeap
        priority_queue<Info, vector<Info>, compare> maxHeap;
        //push all characters into heap, where freq > 0
        for(char i='a'; i<='z'; i++) {
            if(freq[i] > 0) {
                Info temp(i, freq[i]);
                // temp.val = i+'a';
                // temp.count = freq[i];
                maxHeap.push(temp);
            }
        }

        string ans = "";

        while(maxHeap.size() > 1) {
            Info first = maxHeap.top();
            maxHeap.pop();
            Info second = maxHeap.top();
            maxHeap.pop();

            ans.push_back(first.val);
            first.count--;
            ans.push_back(second.val);
            second.count--;

            if(first.count > 0) {
                maxHeap.push(first);
            }
            if(second.count > 0) {
                maxHeap.push(second);
            }
        }

        //if 1 element bacha h, toh alag se handle karo
        if(maxHeap.size() == 1) {
            Info first = maxHeap.top();
            maxHeap.pop();

            ans.push_back(first.val);
            first.count--;

            if(first.count != 0 ) {
                //answer not possible
                return  "";
            }
        }
    return ans;
 
    }
};