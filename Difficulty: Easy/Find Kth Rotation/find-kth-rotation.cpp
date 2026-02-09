class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        vector<int> dupli;
         for(int x: arr){
            dupli.push_back(x);
         }
        sort(dupli.begin(), dupli.end());
        int target = dupli.front();
        // cout<<dupli.front()<<endl;
        int pos = 0;
        int currpos = 0;
        for(int i = 0; i< arr.size(); i++){
            if(arr[i] == target){
                pos = currpos;
            }
            currpos++;
            // cout<<currpos<<endl;
            // pos 
        }
        // cout<<pos;
        return pos;
    }
};
