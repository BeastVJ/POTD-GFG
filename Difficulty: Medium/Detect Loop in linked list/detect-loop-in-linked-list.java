class Solution {
    public boolean detectLoop(Node head) {
        // code here
        Node s=head;
        Node f=head;
        
        while(f != null && f.next != null){
            s=s.next;
            f=f.next.next;
            
            if(s==f){
                return true;
            }
        }
        return false;
    }
}