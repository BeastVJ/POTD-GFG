class Solution:
    def getCount(self, n, d):
        if d>=n:
            return 0
        # code here 
        # 1-9-0    100-109-99    1000-1009-999 100000-99999
        lowest=0
        for i in range(d,n+1):
            sod=sum(map(int, str(i)))
            diff=i-sod
            if diff>=d:
               lowest=i
               break
        if lowest==0:
            return lowest
        return n-lowest+1