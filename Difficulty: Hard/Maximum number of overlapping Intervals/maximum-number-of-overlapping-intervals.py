class Solution:
    def overlapInt(self, arr):
        n = len(arr)
        
        # Separate start and end times
        start = sorted([interval[0] for interval in arr])
        end = sorted([interval[1] for interval in arr])
        
        i = 0  # pointer for start
        j = 0  # pointer for end
        curr_overlap = 0
        max_overlap = 0
        
        while i < n and j < n:
            # If next event is start (inclusive overlap)
            if start[i] <= end[j]:
                curr_overlap += 1
                max_overlap = max(max_overlap, curr_overlap)
                i += 1
            else:
                curr_overlap -= 1
                j += 1
                
        return max_overlap