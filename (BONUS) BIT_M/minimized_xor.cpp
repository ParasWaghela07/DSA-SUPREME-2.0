class Solution {
public:
    bool isSet(int x,int bit){
        return x&(1<<bit);
    }

    int setBit(int x,int bit){
        return x|(1<<bit);
    }

    int unsetBit(int x,int bit){
        return x&~(1<<bit);
    }
    int countSetBits(int num){
        int count=0;
        while(num){
            if(num&1) count++;
            num=num>>1;
        }

        return count;
    }
    int minimizeXor(int num1, int num2) {
        int x=num1;
        int reqSetBits=countSetBits(num2);
        int currSetBits=countSetBits(num1);

        int bit=0;
        if(currSetBits>reqSetBits){
            while(currSetBits>reqSetBits){
                if(isSet(x,bit)){
                    x=unsetBit(x,bit);
                    currSetBits--;
                }
                bit++;
            }
        }
        else if(currSetBits<reqSetBits){
            while(currSetBits<reqSetBits){
                    if(!isSet(x,bit)){
                    x=setBit(x,bit);
                    currSetBits++;
                }
                bit++;
            }
        }
        else x=num1;

        return x;
    }
};

//MIK-1
class Solution {
public:
        //T.C : O(log(n))
        //S.C : O(1)
    bool isSet(int &x, int bit) {
        return x & (1 << bit);
    }

    bool setBit(int &x, int bit) {
        return x |= (1 << bit);
    }

    bool unsetBit(int &x, int bit) {
        return x &= ~(1 << bit);
    }

    int minimizeXor(int num1, int num2) {
        int x = num1;

        int requiredSetBitCount = __builtin_popcount(num2);
        int currSetBitCount = __builtin_popcount(x);

        int bit = 0; //position of bit
        if(currSetBitCount < requiredSetBitCount) {
            while(currSetBitCount < requiredSetBitCount) {
                if(!isSet(x, bit)) {
                    setBit(x, bit);
                    currSetBitCount++;
                }
                bit++;
            }
        } else if(currSetBitCount > requiredSetBitCount) {
            while(currSetBitCount > requiredSetBitCount) {
                if(isSet(x, bit)) {
                    unsetBit(x, bit);
                    currSetBitCount--;
                }
                bit++;
            }
        }

        return x;
    }
};

//MIK-2
class Solution {
public:
    bool isSet(int &x, int bit) {
        return x & (1 << bit);
    }

    bool setBit(int &x, int bit) {
        return x |= (1 << bit);
    }

    bool unsetBit(int &x, int bit) {
        return x &= ~(1 << bit);
    }

    bool isUnset(int x, int bit) {
        return (x & (1 << bit)) == 0;
    }

    int minimizeXor(int num1, int num2) {
        int x = 0;

        int requiredSetBitCount = __builtin_popcount(num2);

        for(int bit = 31; bit >= 0 && requiredSetBitCount > 0; bit--) {
            if(isSet(num1, bit)) {
                setBit(x, bit); //Or you can write x |= (1 << bit);
                requiredSetBitCount--;
            }
        }

        for(int bit = 0; bit < 32 && requiredSetBitCount > 0; bit++) {
            if(isUnset(num1, bit)) {
                setBit(x, bit); //Or you can write x |= (1 << bit);
                requiredSetBitCount--;
            }
        }

        return x;
        
    }
};
