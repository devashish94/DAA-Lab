#include <iostream>
#include <vector>
#include <map>
using namespace std;

void print(const vector<int>& arr) {
  for (const auto& i : arr) {
    cout << i << " ";
  }
  cout << endl;
}

int get_max(const vector<int>& arr) {
  int max = arr[0];
  for (int i = 0; i < arr.size(); i++) {
    if (arr[0] > max) {
      max = arr[0];
    } 
  }
  return max;
}

void counting_sort(vector<int>& arr) {
  int max = get_max(arr);
  int freq[max + 1];

  // initialize hash table array with 0
  for (int i = 0; i < max + 1; i++) {
    freq[i] = 0;
  }

  // store frequencies
  for (const auto& i : arr) {
    freq[i]++;
  }

  // assign values to the array
  int index = 0;
  for (int i = 0; i < max + 1; ) {
    if (freq[i] > 0) {
      arr[index] = i;
      index++;
      freq[i]--;
    } else {
      i++;
    }
  }
}

int main() {
  int n; 
  cin >> n;

  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    arr[i] = t;
  }

  counting_sort(arr);
  print(arr);
}
