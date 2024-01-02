#include<iostream>
#include<stack>

using namespace std;

int main(){
    stack<int>st;
    st.push(5);
    st.push(3);
    st.push(4);
    st.pop();
    st.pop();
    st.pop();
    cout<<st.size()<<endl;
    cout<<st.top()<<endl;

    cout<<st.empty()<<endl;

}