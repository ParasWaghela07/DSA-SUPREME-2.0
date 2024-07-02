class BrowserHistory {
public:
    -------OWN SOLU WITHOUT STACK-----
    vector<string>ans;
    int index=-1;

    BrowserHistory(string homepage) {
        ans.push_back(homepage);
        index=0;
    }
    
    void visit(string url) {
        if(index+1<ans.size()){
            index++;
            ans[index]=url;

            int delSteps=ans.size()-index-1;
            while(delSteps){
                ans.pop_back();
                delSteps--;
            }
        }
        else{
            ans.push_back(url);
            index++;
        }
    }
    
    string back(int steps) {
        while(index>0 && steps){
            index--;
            steps--;
        }

        if(index>=0) return ans[index];
        else return "null";
    }
    
    string forward(int steps) {
        while(index<ans.size()-1 && steps){
            index++;
            steps--;
        }

        if(index<ans.size()) return ans[index];
        else return "null";
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */


-------STACK SOLUTION------

class BrowserHistory {
public:
    stack<string>prev;
    stack<string>forwd;

    BrowserHistory(string homepage) {
        prev.push(homepage);
    }
    
    void visit(string url) {
        prev.push(url);
        while(!forwd.empty()){
            forwd.pop();
        }
    }
    
    string back(int steps) {
        while(prev.size()>1 && steps){
            forwd.push(prev.top());
            prev.pop();
            steps--;
        }

        return prev.top();
    }
    
    string forward(int steps) {
        while(!forwd.empty() && steps){
            prev.push(forwd.top());
            forwd.pop();
            steps--;
        }

        return prev.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */