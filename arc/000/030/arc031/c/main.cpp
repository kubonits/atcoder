#include <limits.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/***RMQ by Segment_tree ***/

const int MAX_N = 1 << 17;

/***BIT ***/

int bit[MAX_N + 1], n;
int sum(int i) {
  int s = 0;
  while (i > 0) {
    s += bit[i];
    i -= i & -i;
  }
  return s;
}

int add(int i, int x) {
  while (i <= n) {
    bit[i] += x;
    i += i & -i;
  }
}

/***RMQ by Segment_tree(structure) ***/

struct SegmentTree {
  int n;
  vector<int> dat;
  SegmentTree(int _n) {
    n = 1;
    while (n < _n) n *= 2;
    dat.resize(2 * n - 1);
    for (int i = 0; i < 2 * n - 1; i++) dat[i] = INT_MAX;
  }

  void update(int k, int a) {
    k += n - 1;
    dat[k] = a;
    while (k > 0) {
      k = (k - 1) / 2;
      dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
  }

  int query(int a, int b, int k, int l, int r) {
    if (r <= a && b <= l) return INT_MAX;  //交差しない
    if (a <= l && r <= b)
      return dat[k];  //完全に含んでいる
    else {
      int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
      int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
      return min(vl, vr);
    }
  }
};

int p[100001], a[100001];

int main() {
  long long ans = 0LL;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    a[p[i]] = i + 1;
  }
  for (int i = n; i > 0; i--) {
    ans += (long long)min(sum(a[i]), sum(n) - sum(a[i]));
    add(a[i], 1);
  }
  cout << ans << endl;
}