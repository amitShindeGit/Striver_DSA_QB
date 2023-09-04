#include <bits/stdc++.h>

int left(int k) { return 2 * k + 1; }

int right(int k) { return 2 * k + 2; }

int parent(int k) { return (k - 1) / 2; }

void insert(vector<int> &heap, int val, int &size) {

  int i = size;

  // might wanna use push_back
  heap[size] = val;

  size += 1;

  while (i != 0 && heap[parent(i)] > heap[i]) {
    swap(heap[parent(i)], heap[i]);

    i = parent(i);
  }
}

void heapify(vector<int> &heap, int k, int &size) {
  int l = left(k);

  int r = right(k);

  int smallest = k;

  if (l < size && heap[l] < heap[k]) {
    smallest = l;
  }

  if (r < size && heap[r] < heap[smallest]) {
    smallest = r;
  }

  if (smallest != k) {
    int temp = heap[k];
    heap[k] = heap[smallest];
    heap[smallest] = temp;

    heapify(heap, smallest, size);
  }
}

int extactMin(vector<int> &heap, int &size) {
  if (size == 1) {
    size -= 1;
    return heap[0];
  }

  int topParent = heap[0];

  heap[0] = heap[size - 1];
  size -= 1;

  heapify(heap, 0, size);

  return topParent;
}

vector<int> minHeap(int n, vector<vector<int>> &q) {
  // Write your code here.
  // Write your code here.
  vector<int> heap(n);
  vector<int> ans;
  int size = 0;

  for (int i = 0; i < n; i++) {
    if (q[i][0] == 0) {
      insert(heap, q[i][1], size);
    } else {
      ans.push_back(extactMin(heap, size));
    }
  }
  return ans;
}
