class Solution:
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if len(nums) == 0:
            return [-1, -1]

        lower = lower_bound(nums, target)
        upper = upper_bound(nums, target)
        if nums[lower] == target and nums[upper] == target:
            solution = [lower, upper]
            return solution
        else:
            return [-1, -1]

        

def lower_bound(nums, target):
    """
    find a first x for which nums[x] >= target is true
    """
    lo = 0
    hi = len(nums) - 1
    while lo < hi:
        mid = lo + (hi - lo) // 2
        if nums[mid] >= target:
            hi = mid
        else:
            lo = mid + 1
    return lo

def upper_bound(nums, target):
    """
    find a last x for which nums[x] > target is false.
    """
    lo = 0
    hi = len(nums) - 1
    while lo < hi:
        mid = lo + (hi - lo + 1) // 2
        if nums[mid] > target:
            hi = mid - 1
        else:
            lo = mid
    return lo

