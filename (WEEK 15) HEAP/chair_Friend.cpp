class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {

        vector<int>t=times[targetFriend];
        priority_queue<int,vector<int>,greater<int>>available;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<std::pair<int, int>>>occupied;

        int n=times.size();
        for(int i=0;i<n;i++){
            available.push(i);
        }

        sort(times.begin(),times.end());

        for(auto it:times){
            while(!occupied.empty() && it[0]>=occupied.top().first){
                available.push(occupied.top().second);
                occupied.pop();
            }

            int chairNum=available.top();
            available.pop();

            if(t==it) return chairNum;
            occupied.push({it[1],chairNum});
        }

        return -1;
    }
};