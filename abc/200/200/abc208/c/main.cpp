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

int main() {
  ll n, k;
  cin >> n >> k;
  vector<int> a(n), b(n);
  vector<pair<int, int> > c;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = 0;
    c.push_back({a[i], i});
  }
  sort(c.begin(), c.end());
  for (int i = 0; i < n; i++) {
    if (k % n > i) {
      b[c[i].second] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << (b[i] ? k / n + 1LL : k / n) << endl;
  }
}