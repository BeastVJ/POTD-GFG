/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
        Node* first = new Node(0);
        first->next = head;
        head = first;
        Node* second, *prev, *curr, *front;
        
        while(first->next) {
            int x = k;
            second = first->next;
            curr = second;
            prev = first;
            while(x-- && curr) {
                front = curr->next;
                curr->next = prev;
                prev = curr;
                curr = front;
            }
            first->next = prev;
            second->next = curr;
            first = second;
            
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        
        return head;
    }
};