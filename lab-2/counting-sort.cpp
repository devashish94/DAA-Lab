#include <iostream>
#include <vector>
#include <map>
using namespace std;

void print(const map<int, int>& m) {
  for (const auto& node : m) {
    cout << node.first << ": " << node.second << endl;
  }
}

void print_array(const vector<int>& arr) {
  for (const auto& i : arr) {
    cout << i << " ";
  }
  cout << endl;
}

vector<int> sort(const vector<int>& arr) {
  map<int, int> m;
  for (const auto& element : arr) {
    m[element]++;
  }
  vector<int> sorted_array;
  for (const auto& node: m) {
    for (int i = 0; i < node.second; i++) {
      sorted_array.push_back(node.first);
    }
  }
  return sorted_array;
}

int main() {
  int length;
  cin >> length;

  vector<int> arr;
  for (int i = 0; i < length; i++) {
    int temp;
    cin >> temp;
    arr.push_back(temp);
  }

  arr = sort(arr);
  print_array(arr);
}
