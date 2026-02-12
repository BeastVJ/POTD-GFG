class Solution:

    def smallestWindow(self, s, p):

        if len(p) > len(s):

            return ""

        

        freq_p = [0] * 26

        freq_s = [0] * 26

        

        for ch in p:

            freq_p[ord(ch) - ord('a')] += 1

        

        required = len(p)

        left = 0

        min_len = float('inf')

        start = -1

        

        for right in range(len(s)):

            idx = ord(s[right]) - ord('a')

            freq_s[idx] += 1

            

            if freq_s[idx] <= freq_p[idx]:

                required -= 1

            

            # Try shrinking the window

            while required == 0:

                window_len = right - left + 1

                if window_len < min_len:

                    min_len = window_len

                    start = left

                

                left_idx = ord(s[left]) - ord('a')

                freq_s[left_idx] -= 1

                if freq_s[left_idx] < freq_p[left_idx]:

                    required += 1

                

                left += 1

        

        if start == -1:

            return ""

        

        return s[start:start + min_len]

