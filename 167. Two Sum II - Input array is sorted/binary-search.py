class Solution:
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        solution = []
        for i in range(len(numbers)):
            real_target = target - numbers[i]
            index = binary_search(numbers, i + 1, real_target)
            if index != -1:
                solution.append(i + 1)
                solution.append(index + 1)
                return solution
    

def binary_search(array, lo, target):
    hi = len(array) - 1
    while lo <= hi:
        mid = (lo + hi) // 2
        if array[mid] == target:
            return mid
        elif array[mid] > target:
            hi = mid - 1
        else:
            lo = mid + 1
    
    return -1