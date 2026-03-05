class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n=s.size(),i=0,j=0,ans=-1;
        unordered_map<int,int> mp;
        
        while(j<n){
            mp[s[j]]++;
            while(mp.size()>k){
                if(--mp[s[i]]==0) mp.erase(s[i]);
                i++;
            }
            if(mp.size()==k) ans=max(ans,j-i+1);
            j++;
        }
        
        return ans;
    }
};