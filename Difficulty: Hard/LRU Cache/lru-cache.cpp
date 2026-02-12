class Node{
    public:
    int  val;
    int key;
    Node* next;
    Node* prev;
    Node(int key, int val){
        this->val= val;
        this->key= key;
        next=prev= nullptr;
    }
};

 

class LRUCache {
    private:
    Node* head;
    Node* tail;
    unordered_map<int , Node*> mp;
    int cap;
  public:
  void delete_Node(Node* node){
      Node* nextNode= node->next;
      Node* prevNode= node->prev;
      prevNode->next= nextNode;
      nextNode->prev= prevNode;
  }
  void insert_Node(Node* node){
      node->next= head->next;
      node->prev= head;;
      head->next->prev= node;
      head->next=node;
      
  }
  
    LRUCache(int cap) {
        // code here
        this->cap= cap;
        head= new Node(-1, -1);
        tail= new Node(-1, -1);
        head->next= tail;
        tail->prev= head;
        mp.clear();
        
    }

    int get(int key) {
        Node* node;
        if(mp.count(key)){
            node= mp[key];
            
        }
        else return -1;
        delete_Node(node);
        insert_Node(node);
        return node->val;
        
        
       
    }

        
    void put(int key, int value) {
        Node* node;
        
        if(mp.count(key)){
            node= mp[key];
            node->val= value;
            delete_Node(node);
            insert_Node(node);
            return;
        }
       
       if(mp.size()==cap){
          Node* lru= tail->prev;
        mp.erase(lru->key);
        delete_Node(lru);
        delete(lru);
       }
       Node* newNode= new Node(key, value);
       mp[key]= newNode;
       insert_Node(newNode);
       
    }
};