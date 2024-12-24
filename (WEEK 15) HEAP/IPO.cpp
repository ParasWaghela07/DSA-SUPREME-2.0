class Solution {
public:
    --O(nlogn)--
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=capital.size();
        priority_queue<int>pq;

        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({capital[i],profits[i]});
        }

        sort(v.begin(),v.end());
        int i=0;

        while(k--){
            while(i<n && v[i].first <= w){
                pq.push(v[i].second);
                i++;
            }
            if(pq.empty()) return w;
            w+=pq.top();
            pq.pop();
        }

        return w;
    }
};

--O(n*k)--worst case->O(n^2)
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=capital.size();
        vector<bool>vis(n,false);

        while(k--){
            int index=-1;
            for(int i=0;i<n;i++){
                if(capital[i]<=w){
                    if((index==-1 || profits[i]>profits[index]) && !vis[i]){
                        index=i;
                    }
                }
            }

            if(index==-1) return w;
            vis[index]=true;

            w+=profits[index];
        }

        return w;
    }
};