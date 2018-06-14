class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        ret = nums[0] + nums[1] + nums[2]
        for i in range(len(nums)):
            l, r = i+1, len(nums) - 1
            while l < r:
                s = nums[i] + nums[l] + nums[r]
                if s == target:
                    return s

                if abs(ret - target) > abs(s - target):
                    ret = s
                
                if s < target:
                    l += 1
                elif s > target:
                    r -= 1
        return ret
            
            


sol = Solution()
nums = [-1, 2, 1, -4]
target = 1
print(sol.threeSumClosest(nums, target))