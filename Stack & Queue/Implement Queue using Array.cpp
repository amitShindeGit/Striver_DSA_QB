class Queue {

  int front, rear;
  vector<int> arr;

public:
  Queue() {
    front = 0;
    rear = 0;
    arr.resize(100001);
  }

  // Enqueue (add) element 'e' at the end of the queue.
  void enqueue(int e) {
    // Write your code here.
    arr[front] = e;
    front++;
  }

  // Dequeue (retrieve) the element from the front of the queue.
  int dequeue() {
    // Write your code here.
    if (rear >= front) {
		return -1;
    }	

	int popedElement = arr[rear];
	rear++;

	return popedElement;

  }
};