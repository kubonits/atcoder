#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;
const int MAX_N = 1 << 17;

int n, dat[2 * MAX_N - 1];

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
  int m, a, left, right, mid, nn;
  cin >> n >> m;
  nn = n;
  init(n);
  for (int i = 0; i < nn; i++) {
    update(i, 0);
  }
  for (int i = 0; i < m; i++) {
    cin >> a;
    left = 0;
    right = nn - 1;
    while (left <= right) {
      mid = (left + right) / 2;
      if (query(0, mid + 1, 0, 0, n) < a) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    if (left < nn) {
      update(left, a);
      cout << left + 1 << endl;
    } else {
      cout << -1 << endl;
    }
  }
}