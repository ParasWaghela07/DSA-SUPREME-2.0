class Solution {
  public:
  //SUBTRACT OR MODULO BETWEEN 2 NUMBERS , ALWAYS (GREATER OP SMALLER) // till any one becomes zero and other nonzero is answer 
    int gcd(int a, int b) {
        if(a==0) return b;
        if(b==0) return a;
        
        while(a>0 && b>0){
            if(a>b){
                a=a-b;
            }
            else{
                b=b-a;
            }
        }
        
        if(a==0) return b;
        else return a;

        //LCM =  (A * B )/GCD;
    }
};