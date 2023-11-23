#include<bits/stdc++.h>
using namespace std;

// vector<int> nextMinNum(vector<int>&qst){
//     vector<int>ans(qst.size());
//     stack<int>st;
//     st.push(-1);

//     for(int i=qst.size()-1;i>=0;i--){
//         while(qst[i]<st.top()){
//             st.pop();
//         }
//         ans[i]=st.top();
//         st.push(qst[i]);
//     }
    
//     return ans;

// }

// vector<int> prevMinNum(vector<int>&qst){
//     vector<int>ans(qst.size());
//     stack<int>st;
//     st.push(-1);

//     for(int i=0;i<qst.size();i++){
//         while(qst[i]<st.top()){
//             st.pop();
//         }
//         ans[i]=st.top();
//         st.push(qst[i]);
//     }
    
//     return ans;


// }

// int main(){

//     vector<int>qst={31,14,15,51};
//     vector<int>ans1;
//     vector<int>ans2;
//     ans1=nextMinNum(qst);
//     ans2=prevMinNum(qst);

//     for(int i=0;i<ans1.size();i++){
//         cout<<ans1[i]<<" ";
//     }

//     cout<<endl;

//     for(int i=0;i<ans2.size();i++){
//         cout<<ans2[i]<<" ";
//     }

//     cout<<endl;


// }


int main(){
    vector<int>ans={1,2,3,4,5};
    reverse(ans.begin(),ans.end());

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}