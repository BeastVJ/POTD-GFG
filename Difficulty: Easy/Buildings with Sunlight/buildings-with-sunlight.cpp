class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        // code here
        int count = 1;
        int currmax= arr[0];
        for(int i = 1; i< arr.size(); i++){
            if(currmax <= arr[i]){
                count++;
                currmax = arr[i];
            }
        }
        return count;
    }
};