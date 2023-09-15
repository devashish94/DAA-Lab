#include <iostream>
#include <vector>
using namespace std;

class Job {
public:
  int id; 
  int p;
  int d;
};

void print(Job arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i].id << " | " << arr[i].p << " | " << arr[i].d << '\n';
  }
}

void print_q(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << '\n';
}

void sort(Job arr[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[i].p > arr[j].p) {
        swap(arr[i], arr[j]);
      }
    }
  }
}

int get_max_d(Job arr[], int n) {
  int max = arr[0].d;
  for (int i = 0; i < n; i++) {
    if (arr[i].d > max) {
      max = arr[i].d;
    }
  }
  return max;
}

int get_total_completed_jobs(int arr[], int n) {
  int total = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] != -1) {
      total++;
    }
  }
  return total;
}

int get_profit(int arr[], int n) {
  int profit = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] != -1) {
      profit += arr[i];
    }
  }
  return profit;
}

int main() {
  int n = 4;
  Job arr[n] = {
    {1, 20, 4},
    {2, 10, 1},
    {3, 40, 2},
    {4, 30, 2}
  }; 

  // sort jobs in decreasing with respect to profit
  sort(arr, n);  

  // get maximum deadline
  int m = get_max_d(arr, n);
  int size_q = m + 1;

  int q[size_q];

  // initialize whole queue to -1
  for (int i = 0; i < size_q; i++) {
    q[i] = -1;
  }

  for (int i = 0; i < n; i++) {
    int j = arr[i].d;
    while (j > 0 && q[j] != -1) {
      j--;
    }
    if (j == 0) {
      break;
    }
    q[j] = arr[i].p; 
  }

  int total_profit = get_profit(q, size_q);
  int total_completed_jobs = get_total_completed_jobs(q, size_q);
  
  cout << "Total Completed Jobs: " << total_completed_jobs << '\n'; 
  cout << "Total Profit: " << total_profit << '\n';
}
