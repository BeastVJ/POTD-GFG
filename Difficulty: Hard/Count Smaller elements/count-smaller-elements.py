class Solution:
    def constructLowerArray(self, arr):
        n = len(arr)
        result = [0] * n
        
        indexed_arr = list(enumerate(arr))
        
        def merge_sort(start, end):
            if end - start <= 1:
                return
            
            mid = (start + end) // 2
            merge_sort(start, mid)
            merge_sort(mid, end)
            
            temp = []
            left = start
            right = mid
            right_count = 0
            
            while left < mid and right < end:
                if indexed_arr[left][1] <= indexed_arr[right][1]:
                    result[indexed_arr[left][0]] += right_count
                    temp.append(indexed_arr[left])
                    left += 1
                else:
                    right_count += 1
                    temp.append(indexed_arr[right])
                    right += 1
            
            while left < mid:
                result[indexed_arr[left][0]] += right_count
                temp.append(indexed_arr[left])
                left += 1
            
            while right < end:
                temp.append(indexed_arr[right])
                right += 1
            
            indexed_arr[start:end] = temp
        
        merge_sort(0, n)
        return result