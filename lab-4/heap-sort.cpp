#include <iostream>
#include <vector>
using std::cout, std::swap, std::endl, std::vector;

void print(std::vector<int>& arr) {
  for (const auto& element : arr) {
    std::cout << element << " ";
  }
  std::cout << '\n';
}

void heapify_largest(vector<int>& arr, int len, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < len && arr[largest] < arr[left]) {
    largest = left;
  } 
  if (right < len && arr[largest] < arr[right]) {
    largest = right;
  }
  if (largest != i) {
    swap(arr[i], arr[largest]);
    heapify_largest(arr, len, largest);
  }
}

void heapify_smallest(vector<int>& arr, int len, int i) {
  int smallest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < len && arr[smallest] > arr[left]) {
    smallest = left;
  } 
  if (right < len && arr[smallest] > arr[right]) {
    smallest = right;
  }
  if (smallest!= i) {
    swap(arr[i], arr[smallest]);
    heapify_smallest(arr, len, smallest);
  }
}

void heap_sort_ascending(vector<int>& arr) {
  for (int i = arr.size() - 1; i >= 0; i--) {
    heapify_largest(arr, arr.size(), i);
  }
  for (int i = arr.size() - 1; i >= 0; i--) {
    swap(arr[0], arr[i]);
    heapify_largest(arr, i, 0);
  }
}

void heap_sort_descending(vector<int>& arr) {
  for (int i = arr.size() - 1; i >= 0; i--) {
    heapify_smallest(arr, arr.size(), i);
  }
  for (int i = arr.size() - 1; i >= 0; i--) {
    swap(arr[0], arr[i]);
    heapify_smallest(arr, i, 0);
  }
}

void insert(vector<int>& arr, int val) {
  int last = arr.size() - 1;
  arr.push_back(val);
  for (int i = last; i >= 0; i--) {
    heapify_largest(arr, arr.size(), i);
  }
}

int remove(vector<int>& arr) {
  int el = arr[0];
  int last = arr.size() - 1;
  swap(arr[0], arr[last]);
  arr.pop_back();
  for (int i = last; i >= 0; i--) {
    heapify_largest(arr, arr.size(), i);
  }
  return el;
}

int main() {
  vector<int> arr = {9,3,2,5,4,6,7,8,1};
  print(arr);

  heap_sort_ascending(arr);
  print(arr);

  heap_sort_descending(arr);
  print(arr);
}
