class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int> mpp;
        int pref=0;
        int len=0;
        int n = arr.size();
        for(int i=0;i<n;i++){
            pref+= arr[i];
            mpp[pref] = i;
            if(pref == k){
                len = i+1;
            }
        }
        
        pref=0;
        for(int i=0;i<n;i++){
            pref+=arr[i];
            int newTar = pref+k;
            if(mpp.find(newTar)!=mpp.end()){
                len = max(len, mpp[newTar] - i);
            }
        }
        return len;
    }
};