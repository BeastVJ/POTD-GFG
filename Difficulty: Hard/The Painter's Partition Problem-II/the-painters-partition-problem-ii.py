class Solution:
    def can(self,arr,mid,k):
        sm=0
        cnt=1
        for ele in arr:
            sm+=ele
            if sm>mid:
                cnt+=1
                sm = ele
        return cnt<=k
        
    def minTime (self, arr, k):
        low = max(arr)
        high = sum(arr)
        while low<high:
            mid = (low+high)//2
            if self.can(arr,mid,k):
                high = mid
            else:
                low = mid+1
        return low