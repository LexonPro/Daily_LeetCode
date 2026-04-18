class Solution {
public:
    int revNum(int num){
        int rem = 0;
        int rev = 0;
        while(num > 0){
            rem = num % 10;
            num /= 10;
            rev = rev * 10 + rem;
        }
        return rev;
    }
     
    int mirrorDistance(int n) {
        return abs(n - revNum(n));
    }
};