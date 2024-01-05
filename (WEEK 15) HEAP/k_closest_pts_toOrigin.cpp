//OWN SOLUTION - 1 // O(N) && O(N)
class Solution {
public:

class compare{
    public:
bool operator()(vector<int>a , vector<int>b){

    int x1=a[0];
    int y1=a[1];
    int x2=b[0];
    int y2=b[1];

    int dis1=x1*x1 + y1*y1;
    int dis2=x2*x2 + y2*y2;

    return dis1>dis2;
}
};
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<vector<int>,vector<vector<int>>,compare>pq;

        for(int i=0;i<points.size();i++){
            pq.push(points[i]);
        }

        while(k--){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};

//OWN SOLUTION-2 // O(N) & O(K)
class Solution {
public:

class compare{
    public:
bool operator()(vector<int>a , vector<int>b){

    int x1=a[0];
    int y1=a[1];
    int x2=b[0];
    int y2=b[1];

    int dis1=x1*x1 + y1*y1;
    int dis2=x2*x2 + y2*y2;

    return dis1 < dis2;
}
};

bool isSmaller(vector<int>a , vector<int>b){

    int x1=a[0];
    int y1=a[1];
    int x2=b[0];
    int y2=b[1];

    int top=x1*x1 + y1*y1;
    int next=x2*x2 + y2*y2;

    if(top > next){
        return true;
    }
    else{
        return false;
    }
}

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<vector<int>,vector<vector<int>>,compare>pq;

        for(int i=0;i<k;i++){
            pq.push(points[i]);
        }

        for(int i=k;i<points.size();i++){
            if(isSmaller(pq.top(),points[i])){
                pq.pop();
                pq.push(points[i]);
            }
        }
        
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};


//LAKSHAY BHAIYA'S SOLUTION

//SAME AS OWN SOLUTION-1 BUT USED PAIR INSTEAD OF VECTOR FOR POINTS