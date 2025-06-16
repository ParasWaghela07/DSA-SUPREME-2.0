#include<bits/stdc++.h>
using namespace std;

class mystack{
    public:
    vector<int>st;

    mystack(){
        
    }

    void push(int data){
        this->st.push_back(data);
    }

    void pop(){
        if(this->st.empty()){
             cout<<"Underflow"<<endl;
        }
        else this->st.pop_back();
    }

    int top(){
        if(this->st.empty()){
             cout<<"Underflow"<<endl;
             return -1;
        }
        else return this->st.back();
    }

    bool isempty(){
        return this->st.empty();
    }

    int size(){
        return this->st.size();
    }
};

void printStack(mystack st){
    while(!st.isempty()){
        cout << st.top() << " ";
        st.pop();
    }
}

int main(){
    mystack st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << "Top element: " << st.top() << endl;
    cout << "Stack size: " << st.size() << endl;

    st.pop();
    cout << "Top after pop: " << st.top() << endl;
    cout << "Stack size after pop: " << st.size() << endl;

    st.pop();
    st.pop();
    st.pop(); // Should print Underflow

    cout << "Is stack empty? " << (st.isempty() ? "Yes" : "No") << endl;

}