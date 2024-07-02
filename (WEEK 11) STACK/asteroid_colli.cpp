class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (auto it : asteroids) {
            
            if (it > 0) st.push(it);
            else {
                int temp = abs(it);
                bool isValid = true;
                while (!st.empty() && st.top() > 0) {
                    if (st.top() < temp) st.pop();
                    else {
                        isValid = false;
                        break;
                    }
                }

                if (isValid) st.push(it);
                else if (st.top() == temp) st.pop();

            }
        }

    vector<int>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(),ans.end());

    return ans;
    }
};