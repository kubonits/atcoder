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

int calc(int x) {
  int res = 0, cnt = 0;
  if (x == 0) {
    return 1;
  }
  for (int i = 0; i < 30; i++) {
    if (x & (1 << i)) {
      cnt++;
    }
  }
  return calc(x % cnt) + 1;
}

int main() {
  int n, cnt = 0, sum[3] = {};
  string s;
  cin >> n >> s;
  vector<int> a(n), b(n), c(n);
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      cnt++;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      sum[j] *= 2;
    }
    if (s[i] == '1') {
      if (cnt > 1) {
        sum[0]++;
      }
      sum[2]++;
    }
    if (cnt > 1) {
      sum[0] %= (cnt - 1);
    }
    sum[2] %= (cnt + 1);
  }
  if (cnt > 1) {
    a[0] = 1 % (cnt - 1);
    for (int i = 1; i < n; i++) {
      a[i] = a[i - 1] * 2;
      a[i] %= (cnt - 1);
    }
  }
  c[0] = 1 % (cnt + 1);
  for (int i = 1; i < n; i++) {
    c[i] = c[i - 1] * 2;
    c[i] %= (cnt + 1);
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == '1' && cnt == 1) {
      cout << 0 << endl;
    } else if (s[i] == '1' && cnt == 2) {
      cout << 1 << endl;
    } else if (s[i] == '1') {
      cout << calc((sum[0] - a[n - 1 - i] + cnt - 1) % (cnt - 1)) << endl;
    } else {
      cout << calc((sum[2] + c[n - 1 - i] + cnt + 1) % (cnt + 1)) << endl;
    }
  }
}