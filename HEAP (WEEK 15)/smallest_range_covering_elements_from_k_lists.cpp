class Solution
{
public:
    class info
    {
    public:
        int data;
        int row;
        int col;

        info(int val, int row, int column)
        {
            this->data = val;
            this->row = row;
            this->col = column;
        }
    };
    class compare
    {
    public:
        bool operator()(info *a, info *b)
        {
            return a->data > b->data;
        }
    };
    vector<int> smallestRange(vector<vector<int>> &nums)
    {

        priority_queue<info *, vector<info *>, compare> pq;
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            info *temp = new info(nums[i][0], i, 0);
            pq.push(temp);
            maxi = max(maxi, nums[i][0]);
            mini = min(mini, nums[i][0]);
        }
        int minAns = mini;
        int maxAns = maxi;

        while (!pq.empty())
        {
            info *temp = pq.top();
            pq.pop();
            int topVal = temp->data;
            int topRow = temp->row;
            int topCol = temp->col;

            mini = topVal;

            if (maxi - mini < maxAns - minAns)
            {
                minAns = mini;
                maxAns = maxi;
            }

            if (topCol + 1 < nums[topRow].size())
            {
                info *temp = new info(nums[topRow][topCol + 1], topRow, topCol + 1);
                pq.push(temp);
                maxi = max(maxi, nums[topRow][topCol + 1]);
            }
            else
            {
                break;
            }
        }

        vector<int> ans;
        ans.push_back(minAns);
        ans.push_back(maxAns);

        return ans;
    }
};