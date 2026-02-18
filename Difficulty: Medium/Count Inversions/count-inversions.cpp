class Solution {
  public:
  
    long long merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        
        long long inv = 0;
        
        while(left <= mid && right <= high) {
            if(arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
                temp.push_back(arr[right]);
                
                // COUNTING INVERSIONS
                inv += (mid - left + 1);
                
                right++;
            }
        }
        
        while(left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
        
        while(right <= high) {
            temp.push_back(arr[right]);
            right++;
        }
        
        for(int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
        
        return inv;
    }
    
    
    long long mergeSort(vector<int> &arr, int low, int high) {
        long long inv = 0;
        
        if(low < high) {
            int mid = (low + high) / 2;
            
            inv += mergeSort(arr, low, mid);
            inv += mergeSort(arr, mid + 1, high);
            inv += merge(arr, low, mid, high);
        }
        
        return inv;
    }
    
    
    long long inversionCount(vector<int> &arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};