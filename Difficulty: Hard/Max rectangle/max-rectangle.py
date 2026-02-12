class Solution:

    def maxArea(self, mat):

        if not mat or not mat[0]:

            return 0

 

        n = len(mat)

        m = len(mat[0])

        heights = [0] * m

        max_area = 0

 

        for i in range(n):

            # Build histogram

            for j in range(m):

                if mat[i][j] == 1:

                    heights[j] += 1

                else:

                    heights[j] = 0

 

            # Calculate max rectangle in histogram

            max_area = max(max_area, self.largestRectangleArea(heights))

 

        return max_area

 

    def largestRectangleArea(self, heights):

        stack = []

        max_area = 0

        heights.append(0) # Sentinel

 

        for i in range(len(heights)):

            while stack and heights[stack[-1]] > heights[i]:

                h = heights[stack.pop()]

                w = i if not stack else i - stack[-1] - 1

                max_area = max(max_area, h * w)

            stack.append(i)

 

        heights.pop()

        return max_area

