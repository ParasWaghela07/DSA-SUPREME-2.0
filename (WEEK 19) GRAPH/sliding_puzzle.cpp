class Solution {
public:

    int slidingPuzzle(vector<vector<int>>& board) {
        string start;
        for(auto it:board){
            for(auto it2:it){
                start.push_back(it2+'0');
            }
        }

        string target="123450";

        unordered_map<int,vector<int>>mp;
        mp[0]={1,3};
        mp[1]={0,2,4};
        mp[2]={1,5};
        mp[3]={0,4};
        mp[4]={1,3,5};
        mp[5]={2,4};

        unordered_map<string,bool>visited;
        visited[start]=true;

        queue<string>q;
        q.push(start);

        int level=0;

        while(!q.empty()){
            int n=q.size();
            while(n--){
                string curr=q.front();
                q.pop();

                if(curr==target) return level;

                int zeroPosi=curr.find('0');
                vector<int>IndexForSwap=mp[zeroPosi];

                for(auto it:IndexForSwap){
                    string s=curr;
                    swap(s[it],s[zeroPosi]);

                    if(visited.find(s)==visited.end()){
                        q.push(s);
                        visited[s]=true;
                    }
                }
            }

            level++;
        }

        return -1;
    }
};