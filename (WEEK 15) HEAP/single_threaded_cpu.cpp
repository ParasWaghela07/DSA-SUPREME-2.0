class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<vector<int>>v;
        for(int i=0;i<tasks.size();i++){
            v.push_back({tasks[i][0],tasks[i][1],i});
        }

        sort(v.begin(),v.end());
        // for(auto it:v) cout<<it[0]<<","<<it[1]<<","<<it[2]<<endl;
        // cout<<endl;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        long long time=0;
        int index=0;
        
        
        vector<int>ans;

        while(index<tasks.size() || !pq.empty()){

            if(pq.empty() && time<v[index][0]) time=v[index][0];
            
            while(index<tasks.size() && v[index][0]<=time){
                pq.push({v[index][1],v[index][2]});
                index++;
            }

            int topTime=pq.top().first;
            int topIndex=pq.top().second;
            pq.pop();

            time+=topTime;
            ans.push_back(topIndex);

            

            // cout<<"Index : "<<index<<endl;
            // cout<<"time : "<<time<<endl<<endl;
        }

        // while(!pq.empty()){
        //     int topTime=pq.top().first;
        //     int topIndex=pq.top().second;
        //     pq.pop();

        //     time+=topTime;
        //     ans.push_back(topIndex);
        // }

        return ans;
    }
};