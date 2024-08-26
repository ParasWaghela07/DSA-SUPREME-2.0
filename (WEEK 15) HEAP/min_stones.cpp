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

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        int sum=0;
        for(int i=0;i<piles.size();i++){
            sum+=piles[i];
            pq.push(piles[i]);
        }

        while(k--){
            int top=pq.top();
            pq.pop();

            sum-=top;

            int newTop=(top&1)?(top/2)+1:top/2;

            sum+=newTop;
            pq.push(newTop);
        }

        return sum;
    }
};