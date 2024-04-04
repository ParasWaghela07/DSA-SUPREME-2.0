class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>times;

        for(int i=0;i<timePoints.size();i++){
            string str1=timePoints[i].substr(0,2);
            string str2=timePoints[i].substr(3,2);

            int hrs=stoi(str1);
            int mins=stoi(str2);

            int totaltime=(hrs*60)+mins;

            times.push_back(totaltime);
        }

        sort(times.begin(),times.end());
        int mintime=1441;
        for(int i=0;i<times.size()-1;i++){
            if(times[i+1]-times[i]<mintime){
                mintime=times[i+1]-times[i];
            }
        }
        return min(mintime,(times[0]+1440)-times[times.size()-1]);
        
    }
};