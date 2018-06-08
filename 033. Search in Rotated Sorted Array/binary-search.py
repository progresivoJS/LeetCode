class Solution:
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if not nums:
            return -1

        pivot = find_pivot(nums)
        if target >= nums[0]:
            index = binary_search(nums, 0, pivot, target)
        else:
            index = binary_search(nums, pivot + 1, len(nums) - 1, target)
        
        if nums[index] != target:
            return -1
        
        return index

def find_pivot(nums):
    """
    find pivot(= peak)
    find a last x for which nums[x] < nums[0] is false.
    """
    lo = 0
    hi = len(nums) - 1
    while lo < hi:
        mid = lo + (hi - lo + 1) // 2
        if nums[mid] < nums[0]:
            hi = mid - 1
        else:
            lo = mid
    return lo



def binary_search(nums, lo, hi, target):
    while lo <= hi:
        mid = lo + (hi - lo) // 2
        if nums[mid] == target:
            return mid
        elif nums[mid] > target:
            hi = mid - 1
        else:
            lo = mid + 1
    return -1