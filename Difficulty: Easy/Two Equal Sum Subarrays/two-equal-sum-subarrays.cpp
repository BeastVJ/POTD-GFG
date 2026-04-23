class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        int totalSum=0;
        int currentSum=0;
        for(int i=0;i<arr.size();i++){
             totalSum+=arr[i];
        }
        int leftSum=totalSum;
        for(int i=arr.size()-1;i>=0;i--){
            currentSum+= arr[i];
            leftSum-=arr[i];
            
            if(currentSum==leftSum)  return true;
            
        }
        return false;
        
    }
};
