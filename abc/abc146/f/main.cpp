#include <deque>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int n, m;
  string s;
  cin >> n >> m >> s;
  vector<int> ans(n + 1);
  deque<pair<int, int> > d;
  for (int i = 0; i < n; i++) {
    ans[i] = -1;
  }
  ans[n] = 0;
  d.push_back({0, n});
  for (int i = n - 1; i >= 0; i--) {
    if (!d.empty() && d[0].second > i + m) {
      d.pop_front();
    }
    if (!d.empty() && s[i] == '0') {
      ans[i] = d[0].first + 1;
      d.push_back({ans[i], i});
    }
  }
  if (ans[0] == -1) {
    cout << -1 << endl;
  } else {
    int p = 0;
    for (int i = 0; i <= n; i++) {
      if (ans[i] == ans[p] - 1) {
        cout << i - p << " ";
        p = i;
      }
    }
    cout << endl;
  }
}