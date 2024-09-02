class Solution {
public:
    class compare{
        public:
        bool operator()(const pair<char,int>&a,const pair<char,int>&b){
            return a.second<b.second;
        }
    };
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<char,int>,vector<pair<char,int>>,compare>pq;
        if(a>0) pq.push({'a',a});
        if(b>0) pq.push({'b',b});
        if(c>0) pq.push({'c',c});

        string ans="";

        while(pq.size()>1){
            auto top1=pq.top();pq.pop();
            auto top2=pq.top();pq.pop();

            ans.push_back(top1.first);
            top1.second--;
            if(top1.second>0){
            ans.push_back(top1.first);
            top1.second--;
            }
            if(top1.second>0){
                pq.push(top1);
            }

            if(top2.second>top1.second){
            ans.push_back(top2.first);
            top2.second--;
            if(top2.second>0){
            ans.push_back(top2.first);
            top2.second--;
            }
            if(top2.second>0){
                pq.push(top2);
            }
            }
            else{
            ans.push_back(top2.first);
            top2.second--;
            if(top2.second>0){
                pq.push(top2);
            } 
            }
        }

        if(!pq.empty()){
            auto top=pq.top();pq.pop();

            if(top.second>=2){
                ans.push_back(top.first);
                ans.push_back(top.first);
            }
            else{
                ans.push_back(top.first);
            }
        }
        return ans;
    }
};