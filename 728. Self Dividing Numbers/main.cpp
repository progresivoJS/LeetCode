class Solution {
private:
    bool isSelfDividing(int num) {
        int temp = num;
        while (temp > 0) {
            int divider = temp % 10;
            if (divider == 0 || num % divider != 0)
                return false;
            temp /= 10;
        }
        return true;
    }
    
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ret;
        for (int i = left; i <= right; i++) {
            if (isSelfDividing(i)) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};