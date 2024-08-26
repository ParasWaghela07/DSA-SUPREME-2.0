class Solution {
public:

    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int>pq;
        int position=startFuel;
        int ans=0;

        for(auto it:stations){
            int currPosi=it[0];
            int currFuel=it[1];

            if(currPosi<=position){
                pq.push(currFuel);
            }
            else{
                while(position < currPosi){
                    if(pq.empty()) return -1;
                    position+=pq.top();
                    pq.pop();

                    ans++;
                }
                pq.push(currFuel);
            }
        }

        if(position>=target) return ans;

        while(position<target){
            if(pq.empty()) return -1;
            position+=pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }
};




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


int minRefuelStops(int target,int startFuel,vector<vector<int>>&stations){
    int stops=0;
    int dist=0;
    int i=0;
    int fuel=startFuel;
    priority_queue<pair<int,int>>pq;

    while(true){
        while(i<stations.size()){
            if(stations[i][0] <= dist + fuel){
                pq.push({station[i][1],stations[i][0]});
            }
            else{
                break;
            }

            i++;
        }

        dist+=fuel;
        fuel=0;

        if(dist>=target) break;

        if(pq.empty()){
            stops=-1;
            break;
        }

        auto&top=pq.top();
        fuel=(dist-top.second) + top.first;
        dist=top.second;
        pq.pop();
        ++stops;
    }
    return stops;
}