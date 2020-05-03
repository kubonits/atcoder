#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
  int n;
  ll cnt = 0;
  vector<ll> a, b;
  priority_queue<pair<ll, int> > q;
  cin >> n;
  a.resize(n);
  b.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    q.push({b[i], i});
  }
  while (!q.empty()) {
    int x, y;
    x = q.top().first;
    y = q.top().second;
    q.pop();
    if (x != a[y]) {
      if (x - b[(n + y - 1) % n] + b[(n + y + 1) % n] < a[y]) {
        cout << -1 << endl;
        return 0;
      }
      int z = (b[y] - max(a[y], (b[(n + y - 1) % n] + b[(n + y + 1) % n]))) /
              (b[(n + y - 1) % n] + b[(n + y + 1) % n]);
      z = max(z, 1);
      cnt += z;
      b[y] -= z * (b[(n + y - 1) % n] + b[(n + y + 1) % n]);
      q.push({b[y], y});
    }
  }
  cout << cnt << endl;
}