class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>cars;
        for(int i=0;i<position.size();i++){
            cars.push_back({position[i],speed[i]});
        }

        sort(cars.begin(),cars.end());

        stack<float>st;
        for(auto it:cars){
            int distance=target-it.first;
            float Speed=(float)it.second;
            float time=(distance/Speed);

            while(!st.empty() && time>=st.top()){
                st.pop();
            }
            st.push(time);
        }

        return st.size();
    }
};