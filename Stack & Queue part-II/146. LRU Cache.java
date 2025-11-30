// DLL 
class Node{
    int key;
    int value;
    Node prev;
    Node next;

    public Node(int key, int value){
        this.key = key;
        this.value = value;
    }
}

class LRUCache {
    private final int capacity;
    private final Map<Integer, Node> mpp;
    private final Node head;
    private final Node tail;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.mpp = new HashMap<>();
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head.next = tail;
        tail.prev = head;
    }
    
    public int get(int key) {
        if(!mpp.containsKey(key)) return -1;
        Node node = mpp.get(key);
        moveAfterHead(node);
        return node.value;
    }
    
    public void put(int key, int value) {
        if(mpp.containsKey(key)){
            Node node = mpp.get(key);
            node.value = value;
            moveAfterHead(node);
        }else{
            if(mpp.size() >= capacity){
                Node lru = tail.prev;
                removeNode(lru);
                mpp.remove(lru.key);
            }

            Node newNode = new Node(key, value);
            addToHead(newNode);
            mpp.put(key, newNode);
        }
    }

    // Use for existing Node
    private void moveAfterHead(Node node){
        removeNode(node);
        addToHead(node);
    }

    // Use for new Node
    private void addToHead(Node node){
        node.next = head.next;
        node.prev = head;
        head.next.prev = node;
        head.next = node;
    }

    private void removeNode(Node node){
        Node prevNode = node.prev;
        Node nextNode = node.next;
        prevNode.next = nextNode;
        nextNode.prev = prevNode;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */