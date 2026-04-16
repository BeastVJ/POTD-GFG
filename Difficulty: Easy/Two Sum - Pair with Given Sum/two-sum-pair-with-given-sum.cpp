class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
       int n=arr.size();
        int i=0;
        int j=n-1;
        sort(arr.begin(),arr.end());
        while(i<j){
            int sum=arr[i]+arr[j];
            if(sum==target){
                return 1;
            }
            else if(sum<target){
                i++;
            }
            else{
                j--;
            }
        }
        return 0;
    }
};