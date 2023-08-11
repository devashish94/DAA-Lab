#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int>& arr) {
  for (const auto& i : arr) {
    cout << i << " ";
  }
  cout << endl;
}

void sort(vector<int>& arr) {
  for (int i = 1; i < arr.size(); i++) {
    int current = arr[i];
    int index = i;
    while (index > 0 && current <= arr[index - 1]) {
      arr[index] = arr[index - 1];
      index--;
    } 
    arr[index] = current;
  }
}

int main() {
  vector<int> arr = {5, 4, 3, 2, 1};
  sort(arr);
  print(arr);
} 
