class Solution {
public:
    
    void reverse(vector<int>& arr, int l, int r) {
        while (l < r) {
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
    }

    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        d = d % n; 

        reverse(arr, 0, d - 1);
        reverse(arr, d, n - 1);
        reverse(arr, 0, n - 1);
    }
};