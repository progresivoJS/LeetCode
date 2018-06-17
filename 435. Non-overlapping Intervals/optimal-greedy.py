import operator

# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
        # self.end = e

class Solution(object):
    def eraseOverlapIntervals(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: int
        """
        intervals.sort(key=operator.attrgetter('end'))
        if len(intervals) == 0:
            return 0
        right_bound = intervals[0]
        count = 1
        for i in range(1, len(intervals)):
            if right_bound.end <= intervals[i].start:
                count += 1
                right_bound = intervals[i]
        
        return len(intervals) - count