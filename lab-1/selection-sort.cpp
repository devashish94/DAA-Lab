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
  int max = start;
  for (int i = start; i <= end; i++) {
    if (arr[i] > arr[max]) {
      max = i;
    }
  }
  return max;
}

int get_min_index(const std::vector<int>& arr, int start, int end) {
  int min = start;
  for (int i = start; i <= end; i++) {
    if (arr[i] < arr[min]) {
      min = i;
    } 
  }
  return min;
}

void selection_sort_max(std::vector<int>& arr) {
  std::cout << "------ maximum element version ------" << std::endl;
  for (int i = 0; i < arr.size(); i++) {
    int last = arr.size() - i - 1;
    int max_index = get_max_index(arr, 0, last);
    swap(arr, last, max_index); 
  }
}

void selection_sort_min(std::vector<int>& arr) {
  std::cout << "------ minimum element version ------" << std::endl;
  for (int i = 0; i < arr.size(); i++) {
    int first = i;
    int small_index = get_min_index(arr, first, arr.size() - 1);
    swap(arr, first, small_index);
  }
}

void recursion_helper(std::vector<int>& arr, int first, int min_index) {
  if (first == arr.size()) {
    return; 
  }
  swap(arr, first, min_index);
  recursion_helper(arr, first + 1, get_min_index(arr, first + 1, arr.size() - 1));
}

void recursive_selection_sort(std::vector<int>& arr) {
  std::cout << "------ recursive minimum element version ------" << std::endl;
  recursion_helper(arr, 0, get_min_index(arr, 0, arr.size() - 1));
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

  // Swap this with any of three available methods
  recursive_selection_sort(arr);

  std::cout << "Sorted array: ";
  print_array(arr);
}
