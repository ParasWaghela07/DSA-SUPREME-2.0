class Solution {
public:
    int minFlips(int a, int b, int c) {
        int temp1=a;
        int temp2=b;
        int temp3=c;
        int ans=0;

        while(temp1 || temp2 || temp3){
            int lb1=temp1&1;
            int lb2=temp2&1;
            int lb3=temp3&1;

            if((lb1|lb2)!=lb3){
                if(lb3==1) ans++;
                else ans+=lb1+lb2;
            }
            temp1=temp1>>1;
            temp2=temp2>>1;
            temp3=temp3>>1;
        }
        return ans;
    }
};

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int result = (a | b) ^ c;
        return __builtin_popcount(result) + __builtin_popcount((a & b) & (result));
    }
};