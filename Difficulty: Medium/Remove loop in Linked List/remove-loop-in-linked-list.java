class Solution {
    public static void removeLoop(Node head) {
        // code here
        if (head == null) return;

        HashSet<Node> visited = new HashSet<>();
        Node curr = head;
        Node prev = null;

        while (curr != null) {
            if (visited.contains(curr)) {
                prev.next = null;
                return;
            }
            visited.add(curr);
            prev = curr;
            curr = curr.next;
        }
    }
}