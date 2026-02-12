class Solution:
    def medianOf2(self, a, b):
        merged = sorted(a + b)
        n = len(merged)

        if n % 2 == 1:
            return merged[n // 2]
        else:
            return (merged[n // 2 - 1] + merged[n // 2]) / 2