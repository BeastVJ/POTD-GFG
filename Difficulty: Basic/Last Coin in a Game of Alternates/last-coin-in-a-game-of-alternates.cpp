class Solution {
  public:
    int coin(vector<int>& arr) {

        int index = 0;
        for(int i=0;i<arr.size();i++)if(arr[i] < arr[index])index = i;
        return arr[index];
        
    }
};