// Code for Selection Sort Algorithm in increasing order
#include <iostream>
#include <vector>

void print_array(const std::vector<int>& arr) {
  for (const auto& element : arr) {
    std::cout << element << " ";
  }
  std::cout << std::endl;
}

void swap(std::vector<int>& arr, int first, int second) {
  int temp = arr[first];
  arr[first] = arr[second];
  arr[second] = temp;
}

int get_max_index(const std::vector<int>& arr, int start, int end) {
  int max = 0;
  for (int i = start; i <= end; i++) {
    if (arr[i] > arr[max]) {
      max = i;
    }
  }
  return max;
}

void selection_sort(std::vector<int>& arr) {
  for (int i = 0; i < arr.size(); i++) {
    int last = arr.size() - i - 1;
    int max_index = get_max_index(arr, 0, last);
    swap(arr, last, max_index); 
  }
}

int main() {
  std::vector<int> arr;
  int length;

  std::cout << "Enter the number of elements: ";
  std::cin >> length; 

  std::cout << "Now enter all the elements separated by a space: "; 
  for (int i = 0; i < length; i++) {
    int temp;
    std::cin >> temp;
    arr.push_back(temp);
  }

  selection_sort(arr);
  std::cout << "Sorted array: ";
  print_array(arr);
}
