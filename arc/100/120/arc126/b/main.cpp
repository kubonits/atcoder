#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;
#include <cstring>

const int MAX_N = 1 << 18;

int n, dat[2 * MAX_N - 1];

void init(int n_) {
  n = 1;
  while (n < n_) {
    n *= 2;
  }
  for (int i = 0; i < 2 * n - 1; i++) {
    dat[i] = 0;
  }
}

void update(int k, int a) {
  k += n - 1;
  dat[k] = a;
  while (k > 0) {
    k = (k - 1) / 2;
    dat[k] = max(dat[k * 2 + 1], dat[k * 2 + 2]);
  }
}

int query(int a, int b, int k, int l, int r) {
  if (r <= a || b <= l) {
    return 0;
  }
  if (a <= l && r <= b) {
    return dat[k];
  } else {
    int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return max(vl, vr);
  }
}

int main() {
  int m, a, b, n_;
  cin >> n >> m;
  n_ = n;
  vector<vector<int> > v(n + 1);
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    v[a].push_back(b);
  }
  for (int i = 1; i <= n; i++) {
    if (!v[i].empty()) {
      sort(v[i].begin(), v[i].end());
    }
  }
  init(n + 1);
  for (int i = 1; i <= n_; i++) {
    while (!v[i].empty()) {
      int x = v[i].back();
      v[i].pop_back();
      update(x, query(1, x, 0, 0, n) + 1);
    }
  }
  cout << query(1, n_ + 1, 0, 0, n) << endl;
}
