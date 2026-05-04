class Solution {
  public:
    vector<int> sortBySetBitCount(vector<int>& arr) {
        // code here
        stable_sort(arr.begin(), arr.end(), [](int a, int b) {
        return __builtin_popcount(a) > __builtin_popcount(b);
    });
        vector<int> ans;
        for(int x: arr){
            ans.push_back(x);
        }
        return ans;
    }
};