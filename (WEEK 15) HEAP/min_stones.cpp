class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        int count=0;
        for(int i=0;i<piles.size();i++){
            pq.push(piles[i]);
            count+=piles[i];
        }

        while(k--){
            int element=pq.top();
            pq.pop();
            count=count-element;
            element=element - (element/2);
            pq.push(element);
            count=count+element;
        }

        return count;
    }
};