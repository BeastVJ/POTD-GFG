/*
class Node {
    int data;
    Node left, right;

    public Node(int d) {
        data = d;
        left = right = null;
    }
}
*/

class Solution {
    public boolean isLeaf(Node root){
        if(root.left==null && root.right==null) return true;
        return false;
    }
    public void leftNode(Node root,ArrayList<Integer> res){
        if(root==null) return;
        
        if(!isLeaf(root)) res.add(root.data);
        if(root.left!=null) leftNode(root.left,res);
        else leftNode(root.right,res);
    }
    public void rightNode(Node root,ArrayList<Integer> res){
        if(root==null) return;
        
        if(root.right!=null) rightNode(root.right,res);
        else rightNode(root.left,res);
        if(!isLeaf(root)) res.add(root.data);
    }
    public void leafNode(Node root,ArrayList<Integer> res){
        if(root==null) return;
        
        if(isLeaf(root)) res.add(root.data);
        leafNode(root.left,res);
        leafNode(root.right,res);
    }
    ArrayList<Integer> boundaryTraversal(Node root) {
        // code here
        ArrayList<Integer> res=new ArrayList<>();
        if(root == null) return res;
        if(!isLeaf(root)) res.add(root.data);
        leftNode(root.left,res);
        leafNode(root,res);
        rightNode(root.right,res);
        return res;
    }
}