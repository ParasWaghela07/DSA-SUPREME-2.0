class Solution {
public:


class info{
    public:
    char ch;
    int count;

    info(char val,int cnt){
        this->ch=val;
        this->count=cnt;
    }
};

class compare{
    public:
    bool operator()(info a,info b){
        return a.count < b.count;
    }
};

    string longestDiverseString(int a, int b, int c) {
        priority_queue<info,vector<info>,compare>pq;
        string ans="";

        if(a>0){
            info temp('a',a);
            pq.push(temp);
        }
        if(b>0){
            info temp('b',b);
            pq.push(temp);
        }
        if(c>0){
            info temp('c',c);
            pq.push(temp);
        }

        while(pq.size()>1){
            info first=pq.top();pq.pop();
            info second=pq.top();pq.pop();

            if(first.count>1){
                ans+=first.ch;
                ans+=first.ch;
                first.count-=2;
            }
            else{
                ans+=first.ch;
                first.count--;
            }
            if(second.count>1 && second.count >= first.count){
                ans+=second.ch;
                ans+=second.ch;
                second.count-=2;
            }
            else{
                ans+=second.ch;
                second.count--;
            }

            if(first.count>0){
                pq.push(first);
            }

            if(second.count>0){
                pq.push(second);
            }
        }

        if(pq.size()==1){
            info temp=pq.top();pq.pop();

            if(temp.count>1){
                ans+=temp.ch;
                ans+=temp.ch;
                temp.count-=2;
            }
            else{
                ans+=temp.ch;
                temp.count--;
            }
        }

        return ans;
    }
};