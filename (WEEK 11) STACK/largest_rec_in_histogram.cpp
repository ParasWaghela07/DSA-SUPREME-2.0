class Solution {
public:
    vector<int> getPrevSmaller(vector<int>&heights){
        stack<int>st;
        st.push(-1);
        vector<int>ans(heights.size());

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

        vector<int> getNextSmaller(vector<int>&heights){
        stack<int>st;
        st.push(heights.size());
        vector<int>ans(heights.size());

        for(int i=heights.size()-1;i>=0;i--){
            int curr=heights[i];

            while(st.top()!=heights.size() && heights[st.top()]>=curr){
                st.pop();
            }

            ans[i]=st.top();
            st.push(i);
        }

        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>prevSmaller=getPrevSmaller(heights);
        vector<int>nextSmaller=getNextSmaller(heights);

        int maxArea=INT_MIN;

        for(int i=0;i<heights.size();i++){
            int width=nextSmaller[i]-prevSmaller[i]-1;
            int height=heights[i];

            maxArea=max(maxArea,width*height);
        }

        return maxArea;
    }
};