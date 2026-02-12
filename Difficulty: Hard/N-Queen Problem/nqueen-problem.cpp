class Solution {
public:
    void solve(int i,vector<int> &v,vector<vector<int>> &ans,vector<vector<int>> &mat,int b,int c,int count[],int count1[],vector<pair<int,int>> pr,int n){
        if(c == n-1){
            ans.push_back(v);
            return ;
        }
        count[0]++;
        count1[i]++;
        pr.push_back({0,i});
        int row = c+1;
        for(int col = 0;col<n;col++){
            if(count[row]  != 0){
                continue;
            }
            if(count1[col] != 0){
                continue;
            }
            int kcnt = 0;
            for(int i = 0;i<pr.size();i++){
                int f = abs(pr[i].first-row);
                int g = abs(pr[i].second-col);
                if(f == g){
                   kcnt++;
                }
            }
            if(kcnt>=1){
                continue;
            }
            //i've already add them here.
            count[row]++;
            count1[col]++;
            pr.push_back({row,col});
            v.push_back(col+1);
            solve(i,v,ans,mat,b,c+1,count,count1,pr,n);
            v.pop_back();
            count[row]--;
            count1[col]--;
            pr.pop_back();
        }
            count[0]--;
            count1[i]--;
            pr.pop_back(); 
            return ;
        
    }
    vector<vector<int>> nQueen(int n) {
        vector<int> v;
        vector<vector<int>> ans;
        vector<vector<int>> mat(n,vector<int>(n,0));
        vector<pair<int,int>> pr;
        int i = 1;
        int b = -1;
        int count[11] = {0};
        int count1[11] = {0};
        for(int i = 0;i<n;i++){
           vector<pair<int,int>> pr;
           int count[11] = {0};
           int count1[11] = {0};
           b = n;
           int c = 0;
           v.push_back(i+1);
           solve(i,v,ans,mat,b,c,count,count1,pr,n);
           v.pop_back();
        }
        return ans;
    }
};