class Solution {
public:

void verticalSumRec(int vLevel, map<int, int> &mp, Node* root) {
    // Base Case
    if(!root) {
        return;
    }
    
    mp[vLevel] += root->data;
    
    // Recursion Call
    verticalSumRec(vLevel-1, mp, root->left);
    verticalSumRec(vLevel+1, mp, root->right);
    
    return;
}

vector<int> verticalSum(Node* root) {
    map<int, int> mp;
    verticalSumRec(0, mp, root);
    
    int size = mp.size();
    vector<int> ans;
    ans.reserve(size);
    
    for(pair<const int, int> &p: mp) {
        ans.push_back(p.second);
    }
    
    return ans;
}

};