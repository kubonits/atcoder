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

int bit[100001], n;

int sum(int i) {
  int s = 0;
  while (i > 0) {
    s += bit[i];
    i -= (i & -i);
  }
  return s;
}

void add(int i, int x) {
  while (i <= n) {
    bit[i] += x;
    i += (i & -i);
  }
}

int main() {
  int l, q, cnt = 1;
  set<int> s;
  cin >> l >> q;
  s.insert(0);
  s.insert(l);
  vector<int> c(q), x(q);
  for (int i = 0; i < q; i++) {
    cin >> c[i] >> x[i];
    if (c[i] == 1) {
      s.insert(x[i]);
    } else {
      int left, right;
      decltype(s)::iterator it = s.lower_bound(x[i]);
      right = *it;
      it--;
      left = *it;
      cout << right - left << endl;
    }
  }
}