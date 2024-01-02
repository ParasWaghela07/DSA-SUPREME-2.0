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

void addatbottom(stack<int> &st,int value){
if(st.empty()){
    st.push(value);
    return;
}

int temp=st.top();
st.pop();
addatbottom(st,value);

st.push(temp);
}

void reverseit(stack<int> &st){
    if(st.empty()){
        return;
    }

    int temp=st.top();
    st.pop();

    reverseit(st);

    addatbottom(st,temp);
}

int main(){
    stack<int>st;

    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);

    // print(st);

    addatbottom(st,500);

    print(st);

    reverseit(st);
    
    print(st);




}