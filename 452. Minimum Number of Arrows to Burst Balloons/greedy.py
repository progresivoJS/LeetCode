import operator

class Solution(object):
    def findMinArrowShots(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        points.sort(key=operator.itemgetter(1))
        if len(points) == 0:
            return 0

        right_bound = points[0]
        
        count = 1
        for point in points[1:]:
            if right_bound[1] < point[0]:
                right_bound = point
                count += 1
        return count