#include <iostream>
#include<stack>
using namespace std;

void solve(stack<int> &st, int& pos, int &ans) {
  if(pos == 1) {
    ans =  st.top();
    cout << "Deleting "<< st.top() << endl;
    st.pop();
    return;
  }

  pos--;
  int temp = st.top();
  st.pop();
  solve(st,pos,ans);
  st.push(temp);
}

int deleteMiddleElement(stack<int> &st) {
  int size = st.size();
  if(st.empty()){
    cout << "Stack is empty, no middle element" << endl;
    return -1;
  }
  else {
    int pos = 0;
    if(size & 1) {
      pos = size/2 + 1;
    }
    else {
      pos = size/2;
    }
    int ans = -1;
    solve(st,pos,ans);
    return ans;
  }
}

int main() {
  stack<int> st;
  st.push(10);
  st.push(20);
  st.push(30);
  st.push(50);
  st.push(60);

  

  cout << "before stack size : " << st.size() << endl; 

  int mid = deleteMiddleElement(st);

  cout << "Deleted Middle element : " << mid << endl;

  cout << "after stack size : " << st.size() << endl; 
  return 0;
}