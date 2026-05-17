class Solution {
public:

vector<int> makeBeautiful(vector<int> &arr) {
    int size = arr.size();
    deque<int> dq;
    
    for(int i =0; i < size; i++) {
        // Same sign
        if( dq.empty() || (dq.back() >= 0 && arr[i] >= 0) || (dq.back() < 0 && arr[i] < 0) ) {
            dq.push_back(arr[i]);
        }
        // Different sign
        else {
            dq.pop_back();
        }
    }
    
    return vector<int> (dq.begin(), dq.end());
}

};