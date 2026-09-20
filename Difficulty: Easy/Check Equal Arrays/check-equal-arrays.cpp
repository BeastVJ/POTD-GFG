class Solution {
  public:
    bool checkEqual(vector<int>& a, vector<int>& b) {
        // code here
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        bool h = true;
        for(int i = 0; i < a.size(); i++){
            if(a[i] != b[i]){
                h = false ;
            }
        }
        return h;
    }
};