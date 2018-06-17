import operator
# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """

        intervals.sort(key=operator.attrgetter('start'))

        if not intervals:
            return intervals
        
        S = []
        S.append(intervals[0])

        for interval in intervals[1:]:
            if S[-1].end < interval.start:
                S.append(interval)
            else:
                S[-1].end = max(S[-1].end, interval.end)
        return S