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
        intervals.sort(key=operator.attrgetter('end', 'start'))
        S = []
        if len(intervals) == 0:
            return 0
        S.append(intervals[0])
        for i in range(1, len(intervals)):
            if S[-1].end <= intervals[i].start:
                S.append(intervals[i])
        
        return len(intervals) - len(S)