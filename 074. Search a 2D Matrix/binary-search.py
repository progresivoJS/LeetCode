class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if len(matrix) == 0:
            return False
        
        row = find_row(matrix, target);
        
        lo = 0
        hi = len(matrix[row]) - 1

        while lo <= hi:
            mid = lo + (hi - lo) // 2
            if matrix[row][mid] == target:
                return True
            elif matrix[row][mid] < target:
                lo = mid + 1
            else:
                hi = mid - 1
        return False
        

def find_row(matrix, target):
    """
    find a last row which matrix[row][0] > target is false.
    """
    lo = 0
    hi = len(matrix) - 1
    while lo < hi:
        mid = lo + (hi - lo + 1) // 2
        if matrix[mid][0] > target:
            hi = mid - 1
        else:
            lo = mid
    return lo