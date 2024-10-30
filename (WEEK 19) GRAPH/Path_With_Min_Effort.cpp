class Solution {
public:
    bool isSafe(int i,int j,int row,int col){
        if(i<0 || j<0 || i>=row || j>=col) return false;
        else return true;
    }
    int minimumEffortPath(vector<vector<int>>& h) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        pq.push({0,{0,0}});

        vector<vector<int>>dist(h.size(),vector<int>(h[0].size(),INT_MAX));
        dist[0][0]=0;

        while(!pq.empty()){
            auto topElement=pq.top();pq.pop();

            int currDist=topElement.first;

            int currX=topElement.second.first;
            int currY=topElement.second.second;

            int dx[4]={1,-1,0,0};
            int dy[4]={0,0,1,-1};

            for(int i=0;i<4;i++){
                int newX=currX+dx[i];
                int newY=currY+dy[i];

                if(isSafe(newX,newY,h.size(),h[0].size())){
                    int newDist=max(currDist,abs(h[newX][newY]-h[currX][currY]));

                    if(newDist < dist[newX][newY]){
                        dist[newX][newY]=newDist;
                        pq.push({newDist,{newX,newY}});
                    }
                }
            }
        }

        return dist[h.size()-1][h[0].size()-1];

    }
};








// class Solution {
// public:
//     bool isSafe(int newX,int newY,int row,int col,int currX,int currY,vector<vector<int>>&dist){
//         if(newX>=0 && newY>=0 && newX<row && newY<col && dist[currX][currY]<dist[newX][newY]){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
//     int minimumEffortPath(vector<vector<int>>& heights) {
//         priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>mini;
//         int row=heights.size();
//         int col=heights[0].size();
//         int destX=row-1;
//         int destY=col-1;
//         vector<vector<int>>dist(row,vector<int>(col,INT_MAX));
//         dist[0][0]=0;
//         mini.push({0,{0,0}});

//         while(!mini.empty()){
//             auto topPair=mini.top();
//             mini.pop();

//             int currDiff=topPair.first;
//             int currX=topPair.second.first;
//             int currY=topPair.second.second;

//             int dx[]={1,0,-1,0};
//             int dy[]={0,1,0,-1};

//             for(int i=0;i<4;i++){
//                 int newX=currX+dx[i];
//                 int newY=currY+dy[i];

//                 if(isSafe(newX,newY,row,col,currX,currY,dist)){
//                     int nbr=heights[newX][newY];
//                     int curr=heights[currX][currY];

//                     int newDiff=max(currDiff,abs(nbr-curr));
//                     dist[newX][newY]=min(dist[newX][newY],newDiff);

//                     if(newX!=destX || newY!=destY){
//                         mini.push({dist[newX][newY],{newX,newY}});
//                     }

//                 }
//             }
//         }

//         return dist[destX][destY];

//     }
// };