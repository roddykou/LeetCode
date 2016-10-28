import sys

class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        tmp, ret = 0, - sys.maxint - 1
        for n in nums:
            tmp += n
            ret = max(ret, tmp)
            if tmp < 0:
                tmp = 0
            
        return ret

solution = Solution()
print solution.maxSubArray([-2,1,-3,4,-1,2,1,-5,4])