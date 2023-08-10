#include <iostream>
#include <vector>

int binary_search(const std::vector<int>& arr, int& target) {
  int left = 0;
  int right = arr.size() - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
}

int main() {
  std::vector<int> arr;
  int length;
  int target;

  std::cout << "Enter the number of elements: ";
  std::cin >> length; 

  std::cout << "Now enter all the elements separated by a space: "; 
  for (int i = 0; i < length; i++) {
    int temp;
    std::cin >> temp;
    arr.push_back(temp);
  }

  std::cout << "Enter the element you want to search: ";
  std::cin >> target;

  int index = binary_search(arr, target);
  if (index == -1) {
    std::cout << "{Not Found} The element was not found in the array" << std::endl;
  } else {
    std::cout << "{Success} The element was found at the index -> " << index << std::endl;
  }
}
