class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();

        int maxOnes=0;
        int index=0;

        for(int i=0;i<row;i++){
            int count=0;
            for(int j=0;j<col;j++){
                if(mat[i][j]==1){
                    count++;
                }
            }
            if(count>maxOnes){
                maxOnes=count;
                index=i;
            }
        }

        return {index,maxOnes};
    }
};