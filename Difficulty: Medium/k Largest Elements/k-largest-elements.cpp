class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // code here
        sort(arr.rbegin(), arr.rend());
        vector<int> ans;
        for(int i = 0 ; i < k; i++){
            ans.push_back(arr[i]);
        }

        return ans;
    }
};