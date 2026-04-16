class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {
        // code here
        int ans = -1;
        for(int i = 0 ; i< arr.size(); i++){
            if(arr[i] == k){
                ans = i;
                break;
            }
        }
        return ans;
    }
};