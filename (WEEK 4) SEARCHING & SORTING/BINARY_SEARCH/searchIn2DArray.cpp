class Solution {
public:
    TIME COMPLEXITY:- O(LOG(M)*LOG(N))
    bool binarySearch(vector<vector<int>>&matrix,int target,int rowNumber){
        int s=0;
        int e=matrix[0].size()-1;

        vector<int>temp=matrix[rowNumber];

        while(s<=e){
            int mid=s+(e-s)/2;

            if(temp[mid]==target){
                return true;
            }
            else if(temp[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }

        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int s=0;
        int e=matrix.size()-1;

        int row=matrix.size();
        int col=matrix[0].size();

        while(s<=e){
            int mid=s+(e-s)/2;

            if(matrix[mid][0]<=target && target<=matrix[mid][col-1]){
                return binarySearch(matrix,target,mid);
            }
            else if(matrix[mid][0]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }

        return false;
    }
};

TIME COMPLEXITY:- O(LOG(M*N));
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();

        int n=row*col;

        int s=0;
        int e=n-1;

        while(s<=e){
            int mid=s+(e-s)/2;
            int rowIndex=mid/col;
            int colIndex=mid%col;

            int value=matrix[rowIndex][colIndex];

            if(value==target){
                return true;
            }
            else if(value>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }

        return false;
    }
};