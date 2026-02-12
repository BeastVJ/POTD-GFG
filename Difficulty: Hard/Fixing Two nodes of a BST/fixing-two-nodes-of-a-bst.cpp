class Solution {
public:
    void solve(Node* root,vector<int> &v){
         if(root == NULL){
             return ;
         }
         solve(root->left,v);
         v.push_back(root->data);
         solve(root->right,v);
    }
    void solvee(int a,int b,Node* root){
         if(root == NULL){
             return ;
         }
         solvee(a,b,root->left);
         if(root->data == a){
            root->data = b;
         }
         else if(root->data == b){
            root->data = a;
         }
         solvee(a,b,root->right);
    }
    void correctBST(Node* root) {
        vector<int> v;
        solve(root,v);
        int a = -1;
        int b = -1;
        bool bl = false;
        int j = -1;
        for(int i = 0;i<v.size()-1;i++){
            if(v[i] > v[i+1] && !bl){
                a = v[i];
                j = i;
                bl = true;
            }
            else if(v[i] > v[i+1] && bl){
                b = v[i+1];
                break;
            }
        }
        if(b == -1){
            b = v[j+1];
        }
        solvee(a,b,root);
    }
};