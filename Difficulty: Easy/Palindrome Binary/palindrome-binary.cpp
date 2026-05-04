class Solution {
  public:
    bool isBinaryPalindrome(int n) {
        int original = n;
        int reverse = 0;

        while(n > 0) {
            int bit = n % 2;          // extract last bit
            reverse = reverse * 2 + bit;
            n = n / 2;
        }

        return original == reverse;
    }
};