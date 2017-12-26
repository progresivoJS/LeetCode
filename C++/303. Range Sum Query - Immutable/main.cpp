// Time : O(n)
// Space : O(n)

class NumArray {
private:
    vector<int> partialSum;
public:
    NumArray(vector<int> nums) {
        int n = nums.size();
        if (n == 0) return;
        partialSum = vector<int>(n);
        partialSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            partialSum[i] = partialSum[i - 1] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        if (i == 0) return partialSum[j];
        return partialSum[j] - partialSum[i - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
