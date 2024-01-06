class Solution
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {

        if (startFuel >= target)
        {
            return 0;
        }
        if (stations.size() == 0)
        {
            return -1;
        }

        int currFuel = startFuel;
        int currDist = 0;
        int stops = 0;

        vector<int> first = stations[0];

        if (currFuel >= first[0])
        {
            currFuel = currFuel - first[0];
            currDist += first[0];
        }
        else
        {
            return -1;
        }

        priority_queue<int> pq;
        pq.push(first[1]);

        int i = 0;
        for (i = 0; i < stations.size(); i++)
        {
            if (i + 1 < stations.size())
            {
                vector<int> temp = stations[i + 1];
                int nextDist = temp[0];
                int nextFuel = temp[1];

                if (currFuel >= nextDist - currDist)
                {
                    currFuel = currFuel - (nextDist - currDist);
                    currDist = nextDist;
                    pq.push(nextFuel);
                }
                else
                {
                    while (currFuel < nextDist - currDist)
                    {
                        if (pq.empty())
                        {
                            return -1;
                        }
                        currFuel += pq.top();
                        pq.pop();
                        stops++;
                    }
                    currFuel = currFuel - (nextDist - currDist);
                    currDist = nextDist;
                    pq.push(nextFuel);
                }
            }
            else
            {
                break;
            }
        }

        if (currFuel >= target)
        {
            return stops;
        }
        else
        {
            while (currFuel < target - currDist)
            {

                if (pq.empty())
                {
                    return -1;
                }
                currFuel += pq.top();
                pq.pop();
                stops++;
            }
            return stops;
        }
    }
};