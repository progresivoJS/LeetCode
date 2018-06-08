class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        find the last x for which p(x) is false
        """
        if x == 0:
            return 0
        lo = 1
        hi = x
        while lo < hi:
            mid = lo + (hi - lo + 1) // 2
            if p(mid, x):
                hi = mid - 1
            else:
                lo = mid
        if p(lo, x):
            return -1
        return lo
        

def p(n, x):
    """
    predicate that n * n > x
    """
    return n  > (x // n)