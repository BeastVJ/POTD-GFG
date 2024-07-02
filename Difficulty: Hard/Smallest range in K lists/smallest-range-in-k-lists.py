#User function Template for python3

import heapq


class Solution:
    def smallestRange(self, KSortedArray, n, k):
        # code here
        # print the smallest range in a new line
        l_range=float("-inf")
        r_range=float("inf")
        res=[]
        curr_max=float("-inf")
        for i in range(k):
            heapq.heappush(res,(KSortedArray[i][0],i,0))
            curr_max = max(curr_max,KSortedArray[i][0])
        # print(res)
        # print(curr_max)
        
        while len(res)>0:
            
            e,i,idx = heapq.heappop(res)
            
            if curr_max-e < r_range - l_range:
                r_range=curr_max
                l_range=e
            next_idx = idx + 1
            if next_idx>=n:
                break
            
            heapq.heappush(res,(KSortedArray[i][next_idx],i,next_idx))
            curr_max=max(curr_max,KSortedArray[i][next_idx])
            
        return [l_range,r_range]


#{ 
 # Driver Code Starts
#Initial Template for Python 3

t=int(input())
for _ in range(t):
    line=input().strip().split()
    n=int(line[0])
    k=int(line[1])
    numbers=[]
    for i in range(k):
        numbers.append([int(x) for x in input().strip().split()])
    r = Solution().smallestRange(numbers, n, k)
    print(r[0],r[1])
# } Driver Code Ends