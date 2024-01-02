#include<iostream>
#include<stack>

using namespace std;

void print(stack<int> st){
    while(st.empty()!=1){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

void InsertInSortedStack(stack<int> &st,int val){
    if(st.empty() || val>st.top()){
        st.push(val);
        return;
    }

    int temp=st.top();
    st.pop();

    InsertInSortedStack(st,val);

    st.push(temp);
}

void SortStack(stack<int> &st){
    if(st.empty()){
        return;
    }
    int temp=st.top();
    st.pop();

    SortStack(st);

    InsertInSortedStack(st,temp);

}

int main(){
    stack<int>st;
    // st.push(1);
    // st.push(5);
    // st.push(9);
    // st.push(15);

    // print(st);

    // InsertInSortedStack(st,3);

    




    st.push(7);
    st.push(4);
    st.push(99);
    st.push(55);
    st.push(34);

    print(st);

    SortStack(st);

    print(st);


}