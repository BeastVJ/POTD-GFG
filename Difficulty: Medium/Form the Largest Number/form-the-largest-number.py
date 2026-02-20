class Solution:

	def findLargest(self, arr):
       
        arr = [str(i) for i in arr]

        def merge(left, mid, right):

            temp = []
            i = left
            j = mid + 1

            while i <= mid and j <= right:
                if arr[i] + arr[j] >= arr[j] + arr[i]:
                    temp.append(arr[i])
                    i += 1
                else:
                    temp.append(arr[j])
                    j += 1
            while i <= mid:
                temp.append(arr[i])
                i += 1

            while j <= right:
                temp.append(arr[j])
                j += 1
            for k in range(len(temp)):
                arr[left + k] = temp[k]
        def mergesort(left, right):
            if left < right:
                mid = (left + right) // 2
                mergesort(left, mid)
                mergesort(mid + 1, right)   
                merge(left, mid, right)
        mergesort(0, len(arr) - 1)

        if arr[0] == '0':
            return '0'

        return ''.join(arr)
	    