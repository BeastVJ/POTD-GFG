class Solution {
  public:
  
        int histogram(vector<int> &arr){
        
        int n = arr.size();
        
        vector<int> leftLarge(n);
        vector<int> rightLarge(n);
        
        
        stack<int> stLarge;
        
        for(int i=n-1;i>=0;i--){
            while(!stLarge.empty()&&arr[stLarge.top()]<=arr[i])stLarge.pop();
            if(stLarge.empty())rightLarge[i]=n;
            else rightLarge[i]=stLarge.top();
            stLarge.push(i);
        }
        
        stack<int> stLarge1;
        
        for(int i=0;i<n;i++){
            while(!stLarge1.empty()&&arr[stLarge1.top()]<arr[i])stLarge1.pop();
            if(stLarge1.empty())leftLarge[i]=-1;
            else leftLarge[i]=stLarge1.top();
            stLarge1.push(i);
        }
        
        vector<int> leftSmall(n);
        vector<int> rightSmall(n);
        
        stack<int> stSmall;
        
        for(int i=n-1;i>=0;i--){
            while(!stSmall.empty()&&arr[stSmall.top()]>=arr[i])stSmall.pop();
            if(stSmall.empty())rightSmall[i]=n;
            else rightSmall[i]=stSmall.top();
            stSmall.push(i);
        }
        
        stack<int> stSmall1;
        
        for(int i=0;i<n;i++){
            while(!stSmall1.empty()&&arr[stSmall1.top()]>arr[i])stSmall1.pop();
            if(stSmall1.empty())leftSmall[i]=-1;
            else leftSmall[i]=stSmall1.top();
            stSmall1.push(i);
        }
        
            long long ans=0;
            
            
            for(int i=0;i<n;i++){
                long long maxCnt = (i - leftLarge[i]) * 1LL * (rightLarge[i] - i);
                long long minCnt = (i - leftSmall[i]) * 1LL * (rightSmall[i] - i);
                ans += (maxCnt - minCnt) * arr[i];
            }
            
            return ans;
    }
    
    int subarrayRanges(vector<int>& arr) {
        // code here
        return histogram(arr);
    }
};