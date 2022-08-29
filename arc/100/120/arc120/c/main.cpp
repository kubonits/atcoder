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
#define MOD2 998244353
using namespace std;
typedef long long ll;
#include <cstring>

int bit[200001], n;

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
  ll ans = 0LL;
  cin >> n;
  vector<int> a(n), b(n);
  map<int, int> m;
  map<int, queue<int> > q;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] += i;
    m[a[i]]++;
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    b[i] += i;
    q[b[i]].push(i + 1);
    if (m.find(b[i]) == m.end() || m[b[i]] == 0) {
      cout << -1 << endl;
      return 0;
    }
    m[b[i]]--;
  }
  for (int i = 0; i < n; i++) {
    ans += (ll)(sum(n) - sum(q[a[i]].front()));
    add(q[a[i]].front(), 1);
    q[a[i]].pop();
  }
  cout << ans << endl;
}
