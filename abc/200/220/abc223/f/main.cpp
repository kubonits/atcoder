#include <algorithm>
#include <climits>
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

int n, dat[2 * MAX_N - 1], q, datb[2 * MAX_N - 1];
int sum[200001];

void init(int n_) {
  n = 1;
  while (n < n_) {
    n *= 2;
  }
  for (int i = 0; i < 2 * n - 1; i++) {
    dat[i] = INT_MAX;
  }
}

void update(int k, int a) {
  k += n - 1;
  dat[k] = a;
  while (k > 0) {
    k = (k - 1) / 2;
    dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
  }
}

void add(int a, int b, int x, int k, int l, int r) {
  if (a <= l || r <= b) {
    datb[k] += x;
  } else if (l < b && a < r) {
    add(a, b, x, k * 2 + 1, l, (l + r) / 2);
    add(a, b, x, k * 2 + 2, (l + r) / 2, r);
  }
}

int query(int a, int b, int k, int l, int r) {
  if (r <= a || b <= l) {
    return INT_MAX;
  }
  if (a <= l && r <= b) {
    return dat[k];
  } else {
    int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return min(vl, vr);
  }
}

int main() {
  int x, l, r;
  string s;
  cin >> n >> q;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '(') {
      sum[i + 1] = sum[i] + 1;
    } else {
      sum[i + 1] = sum[i] - 1;
    }
    update(i + 1, sum[i + 1]);
  }
  for (int i = 0; i < q; i++) {
    cin >> x >> l >> r;
    if (x == 1) {
    }
  }
}
