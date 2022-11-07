class Solution {
public:
    int maximum69Number (int num) {
         for (int i = 1000, n = num; i > 0; n %= i, i /= 10)
            if ((n / i) == 6) return num + i*3;
        return num;
    }
};