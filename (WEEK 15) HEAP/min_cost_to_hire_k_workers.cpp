class Solution {
public:
    // BRUTE FORCE -- O(n*n*logn)---
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        double ans = DBL_MAX; // O(1)
        
        for (int i = 0; i < quality.size(); i++) { // O(n)
            double mr = 1.0 * wage[i] / quality[i]; // O(1)
            priority_queue<double> pq; // O(1)
            double sum = 0; // O(1)
            
            for (int j = 0; j < wage.size(); j++) { // O(n)
                double worker_cost = mr * quality[j]; // O(1)
                if (worker_cost < wage[j]) continue; // O(1)

                sum += worker_cost; // O(1)
                pq.push(worker_cost); // O(log k)

                if (pq.size() > k) { // O(1)
                    sum -= pq.top(); // O(1)
                    pq.pop(); // O(log k)
                }
            }
            if (pq.size() < k) continue; // O(1)

            ans = min(ans, sum); // O(1)
        }

        return ans; // O(1)
    }
};


// BETTER BRUTE FORCE -- O(n*n*logn)--
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        double ans = DBL_MAX; // O(1)
        vector<double> ratios; // O(1)

        for (int i = 0; i < wage.size(); i++) { // O(n)
            ratios.push_back(1.0 * wage[i] / quality[i]); // O(1)
        }

        sort(ratios.begin(), ratios.end()); // O(n log n)
        
        for (int i = k - 1; i < quality.size(); i++) { // O(n)
            double mr = 1.0 * wage[i] / quality[i]; // O(1)
            priority_queue<double> pq; // O(1)
            double sum = 0; // O(1)
            
            for (int j = 0; j < wage.size(); j++) { // O(n)
                double worker_cost = mr * quality[j]; // O(1)
                if (worker_cost < wage[j]) continue; // O(1)

                sum += worker_cost; // O(1)
                pq.push(worker_cost); // O(log k)

                if (pq.size() > k) { // O(1)
                    sum -= pq.top(); // O(1)
                    pq.pop(); // O(log k)
                }
            }
            if (pq.size() < k) continue; // O(1)

            ans = min(ans, sum); // O(1)
        }

        return ans; // O(1)
    }
};

--OPTIMAL--O(n*logn)--
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        double ans=DBL_MAX;
        vector<pair<double,int>>ratios;

        for(int i=0;i<wage.size();i++){ --O(N)
            ratios.push_back({1.0*wage[i]/quality[i],quality[i]});
        }

        sort(ratios.begin(),ratios.end()); --O(NLOGN)
        double mr=ratios[k-1].first;

        priority_queue<int>pq;
        double sum=0;
        for(int i=0;i<k;i++){ --O(K)
            pq.push(ratios[i].second); --O(LOGK)
            sum+=ratios[i].second;
        }
        ans=min(ans,sum*mr);
        
        for(int i=k;i<quality.size();i++){ --O(N)

            mr=ratios[i].first;
            pq.push(ratios[i].second); --O(LOGK)
            sum+=ratios[i].second;

            sum-=pq.top();
            pq.pop(); --O(LOGK)

            ans=min(ans,sum*mr);
        }

        return ans;
    }
};