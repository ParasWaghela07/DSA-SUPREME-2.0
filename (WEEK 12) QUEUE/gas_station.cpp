class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int index=0;
        
        int deficit=0;
        int balance=0;

        for(int i=0;i<gas.size();i++){
            balance+=gas[i]-cost[i];

            if(balance<0){
                deficit+=balance*-1;
                balance=0;
                index=i+1;
            }
        }

        if(balance-deficit>=0){
            return index;
        }
        else{
            return -1;
        }
    }
};


/////--QUEUE BASED

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int front=0;
        int rear=0;

        int gasValue=0;
        int costValue=0;

        bool roundCompleted=false;

        while(front<gas.size()){
            gasValue+=gas[rear];
            costValue+=cost[rear];

            if(gasValue>=costValue){
                rear++;
                if(rear>=gas.size()){
                    rear=0;
                    roundCompleted=true;
                }
                if(rear==front) return rear;
            }
            else{
                if(roundCompleted) break;
                rear++;
                front=rear;
                gasValue=0;
                costValue=0;
            }
        }

        return -1;
    }
};