class Solution {
  public:
    bool check(int h , vector<int> &arr , int k , int w){
        int n = arr.size();
        vector<int>pref(n , 0);
        for(int i = 0; i < n; i++){
            if(i > 0)
                pref[i] += pref[i - 1];
            int H = pref[i] + arr[i];
            int d = H - h;
            if(d < 0){
                k += d;
                pref[i] -= d;
                if(i + w < n)
                    pref[i + w] += d;
            }
        }
        return (k >= 0);
    }
    int maxMinHeight(vector<int> &arr, int k, int w) {
        int start = *min_element(arr.begin() , arr.end());
        int end = start + k , ans = start;
        while(start <= end){
            int mid = (start + end) >> 1;
            if(check(mid , arr , k , w))
                ans = mid , start = mid + 1;
            else
                end = mid - 1;
        }
        return ans;
    }
};