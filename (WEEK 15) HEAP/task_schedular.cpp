class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        for(auto it:tasks) mp[it]++;

        priority_queue<int>pq;
        for(auto it:mp) pq.push(it.second);

        int time=0;
        while(!pq.empty()){
            int top=pq.top();
            pq.pop();

            top--;
            if(top>0){
                time=time+n+1;
                int chch=n;

                vector<int>temp;
                while(chch-- && !pq.empty()){
                    int tp=pq.top();pq.pop();
                    if(tp-1>0) temp.push_back(tp-1);
                }

                for(auto it:temp) pq.push(it);
                pq.push(top);
            }
            else time++;
        }

        return time;
    }
};