class Solution {
public:
    bool isprime(int &n){
        for(int i=2;i<n;i++){
            if(n%i==0) return false;
        }

        return true;
    }
    int countPrimes(int n) {
        int count=0;

        for(int i=2;i<n;i++){
            if(isprime(i)){
                count++;
            }
        }

        return count;
    }
};

//BIT GOOD
class Solution {
public:
    bool isprime(int &n){
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0) return false;
        }

        return true;
    }
    int countPrimes(int n) {
        int count=0;

        for(int i=2;i<n;i++){
            if(isprime(i)){
                count++;
            }
        }

        return count;
    }
};