class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        int ansl=0;
        int ansr=INT_MAX;

        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){--O(K)--
            maxi=max(maxi,nums[i][0]);
            pq.push({nums[i][0],i,0});--O(LOGK)--
        }

        while(pq.size()>=nums.size()){--O(NKLOGK)--
            auto top=pq.top();
            pq.pop();--O(LOGK)--

            int mini=top[0];
            int listIndex=top[1];
            int index=top[2];

            if(maxi-mini<ansr-ansl){
                ansr=maxi;
                ansl=mini;
            }

            if(index+1<nums[listIndex].size()){
                pq.push({nums[listIndex][index+1],listIndex,index+1});--O(LOGK)--
                maxi=max(maxi,nums[listIndex][index+1]);
            }
        }

        return {ansl,ansr};
    }
};


class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++){--O(NK)--
            for(int j=0;j<nums[i].size();j++){
                v.push_back({nums[i][j],i});
            }
        }

        sort(v.begin(),v.end());--O(NKLOGNK)--

        unordered_map<int,int>mp;
        int i=0;
        int j=0;

        int ansl=0;
        int ansr=1e9;

        while(j<v.size()){--O(NK)--
            int num=v[j].first;
            int arr=v[j].second;

            mp[arr]++;

            while(mp.size()==nums.size() && i<=j){
                if(v[j].first-v[i].first < ansr-ansl){
                    ansr=v[j].first;
                    ansl=v[i].first;
                }
                mp[v[i].second]--;
                if(mp[v[i].second]==0) mp.erase(v[i].second);
                i++;
            }

            j++;
        }

        return {ansl,ansr};
    }
};


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
