class Solution:
    def arrangeCoins(self, n):
        """
        :type n: int
        :rtype: int
        find last x for which p(x) is false.
        """
        lo = 0
        hi = n

        while lo < hi:
            mid = lo + (hi - lo + 1) // 2
            if p(mid, n):
                hi = mid - 1
            else:
                lo = mid
        
        if p(lo, n):
            return -1
        return lo

def p(n, target):
    """
    1 + 2 + 3 + ... + n > target
    """
    sum_to_n = n*(n+1) // 2
    return sum_to_n > target