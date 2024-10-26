class Solution {
public:
    bool inBound(int i,int j,int &n,int &m,int &delta){
        if(i-delta<0 || i+delta>=n || j-delta<0 || j+delta>=m) return false;
        else return true;  
    }
    void checkEachPosition(vector<vector<int>>&grid,int i,int j,int &n,int &m,priority_queue<int>&pq){
        int delta=1;
        while(inBound(i,j,n,m,delta)){
            pair<int,int>A={i-delta,j};
            pair<int,int>B={i,j+delta};
            pair<int,int>C={i+delta,j};
            pair<int,int>D={i,j-delta};

            int sum=0;

            int x1=A.first;
            int y1=A.second;

            int x2=B.first;
            int y2=B.second;

            while(x1!=x2 && y1!=y2){
                sum+=grid[x1][y1];
                x1++;
                y1++;
            }

            x2=C.first;
            y2=C.second;

            while(x1!=x2 && y1!=y2){
                sum+=grid[x1][y1];
                x1++;
                y1--;
            }

            x2=D.first;
            y2=D.second;

            while(x1!=x2 && y1!=y2){
                sum+=grid[x1][y1];
                x1--;
                y1--;
            }

            x2=A.first;
            y2=A.second;

            while(x1!=x2 && y1!=y2){
                sum+=grid[x1][y1];
                x1--;
                y1++;
            }

            pq.push(sum);
            delta++;
        }
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        priority_queue<int>pq;
        vector<int>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pq.push(grid[i][j]);
                checkEachPosition(grid,i,j,n,m,pq);
            }
        }

        while(!pq.empty() && ans.size()<3){
            if(ans.size()>0 && ans.back()==pq.top()) pq.pop();
            else{
                ans.push_back(pq.top());
                pq.pop();
            }
        }
        return ans;
    }
};