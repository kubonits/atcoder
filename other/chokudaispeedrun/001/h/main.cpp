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

const int MAX_N = 1 << 17;

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
  int a, ans = 0;
  vector<pair<int, int> > v;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    v.push_back({a, i});
  }
  init(n);
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) {
    int x = query(0, v[i].second + 1, 0, 0, n);
    update(v[i].second, x + 1);
    ans = max(ans, x + 1);
  }
  cout << ans << endl;
}