class Solution {
  public:
    int findPosition(int n) {
        // code here
        if (n <= 0) return -1;

    int position = 1;

    while (n > 1) {
        if (n % 2 != 0) return -1;  // more than one set bit
        n = n / 2;
        position++;
    }

    return position;
    }
};