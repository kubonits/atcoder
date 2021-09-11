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
  int h, w, a, b;
  cin >> h >> w;
  set<int> s;
  for (int i = 1; i <= w; i++) {
    s.insert(i);
  }
  n = w + 1;
  init(n);
  for (int i = 0; i < h; i++) {
    cin >> a >> b;
    if (b + 1 <= w && s.find(b + 1) == s.end()) {
      set<int>::iterator it = s.upper_bound(b);
      if (it != s.begin()) {
        it--;
        update(b + 1, b + 1 - *it + query(*it, *it + 1, 0, 0, n));
        s.insert(b + 1);
      }
    }
    while (s.lower_bound(a) != s.upper_bound(b)) {
      update(*s.lower_bound(a), INT_MAX);
      s.erase(s.lower_bound(a));
    }
    cout << (query(1, w + 1, 0, 0, n) == INT_MAX
                 ? -1
                 : query(1, w + 1, 0, 0, n) + i + 1)
         << endl;
  }
}