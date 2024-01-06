//OWN SOLUTION

class Solution
{
public:
    // class compare
    // {
    // public:
    //     bool operator()(pair<int, int> &a, pair<int, int> &b)
    //     {
    //         return a.first < b.first;
    //     }
    // };
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {

        vector<int> maxi;
        // priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq; // somehow not needed
        priority_queue<pair<int,int>>pq;
        for (int i = 0; i < k; i++)
        {
            pair<int, int> p;
            p.first = nums[i];
            p.second = i;
            pq.push(p);
        }
        maxi.push_back(pq.top().first);
        for (int i = k; i < nums.size(); i++)
        {
            pair<int, int> p;
            p.first = nums[i];
            p.second = i;
            pq.push(p);

            while (i - pq.top().second >= k)
            {
                pq.pop();
            }
            maxi.push_back(pq.top().first);
        }
        return maxi;
    }
};

//LAKSHAY BHAIYA'SOLU is also same