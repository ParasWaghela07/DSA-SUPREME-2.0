//MINE
class Solution {
public:
    //here src is current row and we are traversing thru it , if any other connected node we get ,
    // then we will jump to that node and find for next node
    void dfs(int src,unordered_map<int,bool> &visited,vector<vector<int>>& isConnected){
        visited[src]=true;
        for(int i=0;i<isConnected.size();i++){
            if(!visited[i] && isConnected[src][i]==1){ // src!=i //check
                dfs(i,visited,isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,bool>visited;
        int count=0;
        for(int i=0;i<isConnected.size();i++){
            if(!visited[i]){
                dfs(i,visited,isConnected);
                count++;
            }
        }

        return count;
    }
};

