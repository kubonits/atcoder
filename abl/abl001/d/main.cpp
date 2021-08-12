#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>
using namespace std;
const int MAX_N = 1 << 19;

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
  int k, a, N;
  cin >> N >> k;
  init(300001);
  for (int i = 0; i < N; i++) {
    cin >> a;
    update(a, query(max(a - k, 0), min(300001, a + k) + 1, 0, 0, n) + 1);
  }
  cout << query(0, n, 0, 0, n) << endl;
}