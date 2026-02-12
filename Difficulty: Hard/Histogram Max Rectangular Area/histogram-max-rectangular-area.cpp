class Solution {
    private:
    vector<int> getNext(vector<int> &arr){
        stack<int>st;
        vector<int> ans(arr.size());
        for(int i= arr.size()-1; i>=0; i--){
            int ele= arr[i];
            while(!st.empty() and arr[st.top()]>= ele){
                st.pop();
            }
            if(st.empty()){
                ans[i]= arr.size();
            }else ans[i]= st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> getPrev(vector<int> &arr){
        stack<int> st;
        vector<int> ans(arr.size());
        st.push(-1);
        for(int i=0; i<arr.size(); i++){
            int ele= arr[i];
            while(st.top()!=-1 and arr[st.top()]>= ele){
                st.pop();
            }
            ans[i]= st.top();
            st.push(i);
        }
        return ans;
        
    }
  public:
    int getMaxArea(vector<int> &arr) {
        vector<int> next= getNext(arr);
        vector<int> prev= getPrev(arr);
        int maxi= INT_MIN;
        for(int i=0; i<arr.size(); i++){
            int width= next[i] - prev[i] -1;
            int length= arr[i];
            int total= width * length;
            maxi= max(maxi, total);
        }
        return maxi;
        
    }
};