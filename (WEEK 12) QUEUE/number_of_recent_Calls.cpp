class RecentCounter {
public:

queue<int>q; //calls between t and t-3000
    RecentCounter() {
        
    }
    
    int ping(int t) {
        
        int low=t-3000;

        while(!q.empty() && q.front()<low){
            q.pop();
        }

        q.push(t);

        return q.size();
    }
};