class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>pq;
        pq.push({1,0+arr[0]});
        for(int i=1;i<arr.size() ; i++){
            while(pq.size() >0 && pq.top().second <i)pq.pop();
            if(pq.empty())return -1;
            if(i == arr.size() -1)return pq.top().first;
            pq.push({pq.top().first+1 , i+arr[i]});
        }
    }
};