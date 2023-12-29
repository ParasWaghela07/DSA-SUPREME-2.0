// METHOD 1 :
    //  INSERTION : O(N)
    //  DELETION/PEEK: O(1)
    //EMPTY : O(1)
    class MyQueue {
public:
stack<int>s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int popped=s1.top();
        s1.pop();

        return popped;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        if(s1.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */





// METHOD 2 :
    //  INSERTION : O(1)
    //  DELETION/PEEK : O(N)
    //EMPTY : O(1)

class MyQueue {
public:
stack<int>s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int popped=-1;
        if(!s2.empty()){
            popped=s2.top();
            s2.pop();
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }

            popped=s2.top();
            s2.pop();
        }

        return popped;
    }
    
    int peek() {
        int peeked=-1;
        if(!s2.empty()){
            peeked=s2.top();
        }
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }

            peeked=s2.top();
        }

        return peeked;

    }
    
    bool empty() {
        if(s1.empty() && s2.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */