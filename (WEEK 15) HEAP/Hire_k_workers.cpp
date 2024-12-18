
class Solution {
public:
--  1-HEAP --
    long long totalCost(vector<int>& costs, int k, int c) {
        long long ans=0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;

        int i=0;
        int j=costs.size()-1;

        int temp=c;
        while(i<=j && temp--){
            pq.push({costs[i],i,-1});
            i++;
        }
        
        temp=c;
        while(j>=i && temp--){
            pq.push({costs[j],j,1});
            j--;
        }

        while(k--){
            auto top=pq.top();
            pq.pop();

            ans+=top[0];
            if(top[2]==-1 && i<=j){
                pq.push({costs[i],i,-1});
                i++;
            }
            else if(j>=i){
                pq.push({costs[j],j,1});
                j--;
            }
        }

        return ans;
    }
};


---2-HEAP--

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int c) {
        long long ans=0;
        priority_queue<int,vector<int>,greater<int>>pq1,pq2;

        int i=0;
        int j=costs.size()-1;

        while(k--){

            while(pq1.size()<c && i<=j){
                pq1.push(costs[i]);
                i++;
            }

            while(pq2.size()<c && j>=i){
                pq2.push(costs[j]);
                j--;
            }

            int min1=pq1.empty() ? INT_MAX : pq1.top();
            int min2=pq2.empty() ? INT_MAX : pq2.top();

            if(min1 <= min2){
                ans+=min1;
                pq1.pop();
            }
            else{
                ans+=min2;
                pq2.pop();
            }
        }

        return ans;
    }
};


class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int c) {
        long long ans=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq2;

        int i=0;
        int j=costs.size()-1;

        int temp=c;
        while(i<=j && temp--){
            pq1.push({costs[i],i});
            i++;
        }
        
        temp=c;
        while(j>=i && temp--){
            pq2.push({costs[j],j});
            j--;
        }

        pq1.push({10000000,10000000});
        pq2.push({10000000,10000000});
        while(k--){
            
            auto candi1=pq1.top();
            pq1.pop();

            auto candi2=pq2.top();
            pq2.pop();

            if(candi1.first<=candi2.first){
                
                ans+=candi1.first;
                pq2.push({candi2.first,candi2.second});
                if(i<=j){
                    pq1.push({costs[i],i});
                    i++;
                }
            }
            else{
                
                ans+=candi2.first;
                pq1.push({candi1.first,candi1.second});
                if(j>=i){
                    pq2.push({costs[j],j});
                    j--;
                }
            }
        }

        return ans;
    }
};

class Solution {
public:
    // ---BRUTE FORCE---
    long long totalCost(vector<int>& costs, int k, int c) {
        long long ans=0;

        while(k--){
            int mini=1e9;
            int index=-1;

            int i=0;
            int temp=c;
            while(i<costs.size() && temp){
                if(costs[i]==1e9){
                    i++;
                    continue;
                }

                if(costs[i]<mini){
                    mini=costs[i];
                    index=i;
                }
                i++;
                temp--;
            }

            int j=costs.size()-1;
            temp=c;

            while(j>i && temp){
                if(costs[j]==1e9){
                    j--;
                    continue;
                }

                if(costs[j]==mini && j<index) index=j;
                if(costs[j]<mini){
                    mini=costs[j];
                    index=j;
                }
                j--;
                temp--;
            }

            ans+=mini;
            costs[index]=1e9;

        }

        return ans;
    }
};