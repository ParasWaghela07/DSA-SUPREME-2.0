#include <bits/stdc++.h>
using namespace std;
// next smaller element
vector<int> nextSmaller(int *arr, int n)
{
    stack<int> st;
    vector<int> ans;
    st.push(-1);
    for (int i = n - 1; i >= 0; i--)
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
    vector<int> ans = nextSmaller(arr, n);

    for (int i=ans.size()-1;i>=0;i--)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
