class Solution {
public:
    bool isPowerOfFour(int num) {
        return (num > 0) && ((num & (num - 1)) == 0) && ((nums - 1) % 3 == 0);
    }
};