/*
Definition for Node
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  bool result=false;
    bool compare(Node* a,Node* b){
        if(a == NULL && b==NULL)return true;
        if(a==NULL || b==NULL || a->data !=b->data)return false;
        if(a->data == b->data && b->left==NULL && b->right==NULL)return true;
        
        return compare(a->right,b->right) && compare(a->left,b->left);
    }
    void find(Node* root,Node *root2,int dataa){
        if(root==NULL)return;
        
        if(root->data==dataa){
            if(compare(root,root2)==true)
            {
                result=compare(root,root2);
                return;
            }
        }
        
        //right check
        find(root->right,root2,dataa);
        //left check
        find(root->left,root2,dataa);
        
        
    }
    bool isSubTree(Node *root1, Node *root2) {
        find(root1,root2,root2->data);
        return result;
        
    }
};