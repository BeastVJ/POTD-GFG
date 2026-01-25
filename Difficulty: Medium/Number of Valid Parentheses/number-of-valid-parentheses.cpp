class Solution {
  public:
    
    int countValid(int open, int close){
        if(close < open) return 0;
        
        if(!open) return 1;
        
        return countValid(open - 1, close) + countValid(open, close - 1);
    }
    int findWays(int n) {
        // code here
        if(n %2 == 1) return 0;
        return countValid(n/ 2 , n/ 2);
    }
};