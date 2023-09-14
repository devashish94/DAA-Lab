#include <iostream>
using namespace std;

class Item {
public:
  int id;
  int profit;
  int weight;
  double pw;

  Item () {
    id = 0;
    profit = 0;
    weight = 0;
    pw = 0.0;
  }

  Item (int i, int p, int w) {
    id = i;
    profit = p;
    weight = w;
    pw = (double) p / (double) w;
  }
};

void print(Item arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << "ID: " << arr[i].id << " | " << "Profit: " << arr[i].profit << " | " << "Weight: " << arr[i].weight << " | " << "P/W: " << arr[i].pw << '\n';
  }
}

/* 
  Currently the Sorting Algorithm runs in O(n^2)
  Optimize this to O(n.log(n))
*/
void sort(Item arr[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[i].pw > arr[j].pw) {
        swap(arr[i], arr[j]);
      }
    }
  }
}

int main() {
  int n = 7;
  int m = 15;

  Item items[n] = {
    {1, 10, 2},
    {2, 5, 3},
    {3, 15, 5},
    {4, 7, 7},
    {5, 6, 1},
    {6, 18, 4},
    {7, 3, 1}
  };

  sort(items, n);
  print(items, n);

  double total_profit = 0;

  int i = 0;
  for (i = 0; i < n; i++) {
    if (m - items[i].weight > 0) {
      total_profit += items[i].profit;
      m -= items[i].weight;
    } else {
      break;
    }
  }

  if (m != 0) {
    total_profit += m * items[i].pw;
    m -= m;
  }
  cout << "Maximum Profit through Greedy Approach is: " << total_profit << " units" << '\n';
}
