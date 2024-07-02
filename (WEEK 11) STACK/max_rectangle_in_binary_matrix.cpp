class Solution {
public:
vector<int> nextMinNum(vector<int>&heights){

    vector<int>ans(heights.size());
    stack<int>st;
    st.push(-1);

    for(int i=heights.size()-1;i>=0;i--){
        int curr=heights[i];
        while(st.top()!=-1 && heights[st.top()]>=curr){
            st.pop();
        }
        ans[i]=st.top();
        st.push(i);
    }
    
    return ans;

}

vector<int> prevMinNum(vector<int>&heights){
    vector<int>ans(heights.size());
    stack<int>st;
    st.push(-1);

    for(int i=0;i<heights.size();i++){
        int curr=heights[i];
        while(st.top()!=-1 && heights[st.top()]>=curr){
            st.pop();
        }
        ans[i]=st.top();
        st.push(i);
    }
    
    return ans;


}

    int largestRectangleArea(vector<int>& heights) {

        vector<int>next=nextMinNum(heights);
        for(int i=0;i<next.size();i++){
            if(next[i]==-1){
                next[i]=next.size();
            }
        }
        vector<int>prev=prevMinNum(heights);
        int MaxArea=INT_MIN;
        for(int i=0;i<heights.size();i++){
            int width=next[i]-prev[i]-1;
            int currArea=width*heights[i];
            MaxArea=max(MaxArea,currArea);
        }

        return MaxArea;
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int>v;
        int n=matrix.size();
        int m=matrix[0].size();

        for(int i=0;i<m;i++){
            v.push_back(matrix[0][i]-'0');
        }

        int area=largestRectangleArea(v);

        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    v[j]+=matrix[i][j]-'0';
                }
                else{
                    v[j]=0;
                }
            }
            area=max(area,largestRectangleArea(v));
        }

        return area;
    }
};



class Solution {
public:
vector<int> nextMinNum(vector<int>&heights){

    vector<int>ans(heights.size());
    stack<int>st;
    st.push(-1);

    for(int i=heights.size()-1;i>=0;i--){
        int curr=heights[i];
        while(st.top()!=-1 && heights[st.top()]>=curr){
            st.pop();
        }
        ans[i]=st.top();
        st.push(i);
    }
    
    return ans;

}

vector<int> prevMinNum(vector<int>&heights){
    vector<int>ans(heights.size());
    stack<int>st;
    st.push(-1);

    for(int i=0;i<heights.size();i++){
        int curr=heights[i];
        while(st.top()!=-1 && heights[st.top()]>=curr){
            st.pop();
        }
        ans[i]=st.top();
        st.push(i);
    }
    
    return ans;


}

    int largestRectangleArea(vector<int>& heights) {

        vector<int>next=nextMinNum(heights);
        for(int i=0;i<next.size();i++){
            if(next[i]==-1){
                next[i]=next.size();
            }
        }
        vector<int>prev=prevMinNum(heights);
        int MaxArea=INT_MIN;
        for(int i=0;i<heights.size();i++){
            int width=next[i]-prev[i]-1;
            int currArea=width*heights[i];
            MaxArea=max(MaxArea,currArea);
        }

        return MaxArea;
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>>v;
        int n=matrix.size();
        int m=matrix[0].size();

        for(int i=0;i<n;i++){
            vector<int>t;
            for(int j=0;j<m;j++){
                t.push_back(matrix[i][j]-'0');
            }
            v.push_back(t);
        }

        int area=largestRectangleArea(v[0]);

        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]){
                    v[i][j]+=v[i-1][j];
                }
                else{
                    v[i][j]=0;
                }
            }
            area=max(area,largestRectangleArea(v[i]));
        }

        return area;
    }
};