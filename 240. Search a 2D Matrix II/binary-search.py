class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """

        if len(matrix) == 0 or len(matrix[0]) == 0:
            return False

        # row -> col
        col_index = self.find_in_row(matrix[0], target)
        for index in range(col_index + 1):
            row_index = self.find_in_col(matrix, index, target)
            if matrix[row_index][index] == target:
                return True
        return False
        
    
    def find_in_col(self, matrix, col_index, target):
        """
        find a last x for which matrix[x][col_index] > target is false.
        """
        lo = 0
        hi = len(matrix) - 1
        while lo < hi:
            mid = lo + (hi - lo + 1) // 2
            if matrix[mid][col_index] > target:
                hi = mid - 1
            else:
                lo = mid
        return lo

    def find_in_row(self, row_list, target):
        """
        find a last x for which row_list[x] > target is false.
        """
        lo = 0
        hi = len(row_list) - 1
        while lo < hi:
            mid = lo + (hi - lo + 1) // 2
            if row_list[mid] > target:
                hi = mid - 1
            else:
                lo = mid
        
        return lo