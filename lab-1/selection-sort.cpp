// Code for Selection Sort Algorithm in increasing order
#include <iostream>
#include <vector>
using namespace std;

void print_array(const vector<int>& arr) {
  for (const auto& element : arr) {
    cout << element << " ";
  }
  cout << endl;
}

void swap(vector<int>& arr, int first, int second) {
  int temp = arr[first];
  arr[first] = arr[second];
  arr[second] = temp;
}

int get_max_index(const vector<int>& arr, int start, int end) {
  int max = 0;
  for (int i = start; i <= end; i++) {
    if (arr[i] > arr[max]) {
      max = i;
    }
  }
  return max;
}

void selection_sort(vector<int>& arr) {
  for (int i = 0; i < arr.size(); i++) {
    int last = arr.size() - i - 1;
    int max_index = get_max_index(arr, 0, last);
    swap(arr, last, max_index); 
  }
}

int main() {
  vector<int> arr = {5, 4, 3, 2, 1};
  selection_sort(arr);
  print_array(arr);
}
