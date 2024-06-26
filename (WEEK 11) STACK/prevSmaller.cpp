#include <bits/stdc++.h>
using namespace std;

// prev Smaller
vector<int> prevSmaller(int *arr, int n)
{
    stack<int> st;
    vector<int> ans;
    st.push(-1);
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (st.top() >= curr)
        {
            st.pop();
        }
        ans.push_back(st.top());
        st.push(curr);
    }
    return ans;
}

int main()
{
    int arr[5] = {8, 4, 6, 2, 3};
    int n = 5;

    vector<int> ans1 = prevSmaller(arr, n);

    for (auto i : ans1)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
