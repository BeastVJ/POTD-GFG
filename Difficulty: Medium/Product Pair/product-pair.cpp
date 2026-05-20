class Solution {
public:

bool isProduct(vector<int> &arr, long long target) {
    unordered_map<long long, int> mp;
    
    for(int &val: arr) {
        mp[1LL * val]++;
    }
    
    for(int &val: arr) {
        // Edge case
        if(val == 0) {
            if(target == 0) {
                return true;
            }
            else {
                continue;
            }
        }
        
        long long div = target / val;
        
        // Target is a square
        if(div == val) {
            if(mp[val] > 1 && val * val == target) {
                return true;
            } 
        }
        // a * b
        else if(mp.count(div)) {
            if(val * div == target) {
                return true;
            } 
        }
    }
    
    return false;
}

};