#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
int n, t[100000], p = 0, l, r, mid;
ll x, sum, a[100000];
priority_queue<ll, vector<ll>, greater<ll> > q;
vector<ll> v[100001];
int main() {
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    v[t[i]].push_back(a[i]);
  }
  l = 1;
  r = 100000;
  while (l <= r) {
    mid = (l + r) / 2;
    while (!q.empty()) {
      q.pop();
    }
    sum = 0LL;
    for (int i = 1; i <= 100000; i++) {
      for (int j = 0; j < v[i].size(); j++) {
        if (q.size() < min(i, mid)) {
          sum += v[i][j];
          q.push(v[i][j]);
        } else if (q.top() < v[i][j]) {
          sum -= q.top();
          q.pop();
          sum += v[i][j];
          q.push(v[i][j]);
        }
      }
    }
    if (sum >= x) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  if (l > 100000) {
    cout << -1 << endl;
  } else {
    cout << l << endl;
  }
}