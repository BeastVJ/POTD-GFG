class Solution {
    
    boolean isValidBST(Node root, long min, long max){
        if(root==null) return true;  
        
        if (root.data <= min || root.data >= max) return false;

        boolean isLeftBST = isValidBST(root.left, min, root.data);
        
        boolean isRightBST = isValidBST(root.right, root.data, max);

        return isLeftBST && isRightBST;
    }
    
    boolean isBST(Node root) {
        // Recursively check for BST using global min and max
        long min = Long.MIN_VALUE;
        long max = Long.MAX_VALUE;
        return isValidBST(root, min, max);
    }
}