#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int n, k, x;
  priority_queue<pair<int, int> > q;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> x;
    q.push({x, i + 1});
    if (q.size() > k) {
      q.pop();
    }
    if (q.size() == k) {
      cout << q.top().second << endl;
    }
  }
}