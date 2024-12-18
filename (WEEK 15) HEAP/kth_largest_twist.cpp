
class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K=k;
        for(auto it:nums){
            if(pq.size()<k) pq.push(it);
            else if(it>pq.top()){
                pq.pop();
                pq.push(it);
            }
        }
    }
    
    int add(int val) {
        pq.push(val);

        if(pq.size()>K) pq.pop();

        return pq.top();
    }
};



class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    KthLargest(int k, vector<int>& nums) {
        for(auto it:nums){
            if(pq.size()<k) pq.push(it);
            else if(it>pq.top()){
                pq.pop();
                pq.push(it);
            }
        }

        while(pq.size()<k){
            pq.push(INT_MIN);
            k--;
        }
    }
    
    int add(int val) {
        if(val>pq.top()){
            pq.pop();
            pq.push(val);
        }

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */