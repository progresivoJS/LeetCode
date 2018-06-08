class Solution(object):
    def nextGreatestLetter(self, letters, target):
        """
        :type letters: List[str]
        :type target: str
        :rtype: str
        find a first x for which letters[x] > target.
        """
        
        lo = 0
        hi = len(letters) - 1
        while lo < hi:
            mid = lo + (hi - lo) // 2
            if letters[mid] > target:
                hi = mid
            else:
                lo = mid + 1
        if not letters[lo] > target:
            return letters[0]
        return letters[lo]