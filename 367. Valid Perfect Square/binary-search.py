class Solution(object):
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        find a first x for which x * x >= num is true.
        """
        lo = 1
        hi = num
        while lo < hi:
            mid = lo + (hi - lo) // 2
            if mid * mid >= num:
                hi = mid
            else:
                lo = mid + 1
        print(lo)
        return lo * lo == num