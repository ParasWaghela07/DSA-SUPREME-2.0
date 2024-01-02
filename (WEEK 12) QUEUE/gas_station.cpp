class Solution {
public:
//BABBAR'S SOLU
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int prev_cost=0;
        int curr_cost=0;

        //index from where we ares starting
        int start=0;

        for(int i=0;i<gas.size();i++){
            curr_cost+=gas[i]-cost[i];

            if(curr_cost<0){
                prev_cost+=abs(curr_cost);
                start=i+1;
                curr_cost=0;
            }
        }

        if(curr_cost-prev_cost>=0){
            return start;
        }
        else{
            return -1;
        }

    }
};


//RANDOM SOLU
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int total_gas=0,total_cost=0;
        int curr_gas=0, starting_point=0;
        for(int i=0;i<n;i++)
        {
            //these two variable are to check if no case is possible
            total_gas+=gas[i];
            total_cost+=cost[i];
            //for checking the total present gas at index i
            curr_gas+=gas[i]-cost[i];
            if(curr_gas<0)
            {
               //there is a breakdown....so we will start from next point or index
                starting_point=i+1;
                //reset our fuel 
                curr_gas=0;
            }
        }
        return (total_gas<total_cost)?-1:starting_point;     
    }
};