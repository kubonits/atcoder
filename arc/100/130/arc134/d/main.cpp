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

int main() {
  int n, mini = 1000000000, maxi = 0;
  cin >> n;
  vector<int> a(2 * n);
  map<int, int> m, ma;
  for (int i = 0; i < 2 * n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    mini = min(mini, a[i]);
    if (m.find(a[i]) == m.end()) {
      m.insert({a[i], a[i + n]});
      ma.insert({a[i], a[i + n]});
    } else {
      m[a[i]] = min(m[a[i]], a[i + n]);
      ma[a[i]] = max(ma[a[i]], a[i + n]);
    }
  }

  vector<int> ansf, ansb, v(n + 1);
  if (mini >= m[mini]) {
    ansf.push_back(mini);
    ansb.push_back(m[mini]);
  } else {
    int p = n - 1;
    v[n] = 1000000000;
    for (int i = n - 1; i >= 0; i--) {
      v[i] = min(v[i + 1], a[i]);
      if (a[i] == mini) {
        p = i;
      }
    }
    maxi = a[p + n];
    for (int i = 0; i < n; i++) {
      if (a[i] == v[i] && a[i] <= a[p + n] &&
          (a[i] == mini || a[p + n] < maxi || a[p + n] > a[i])) {
        ansf.push_back(a[i]);
        ansb.push_back(a[i + n]);
        if (maxi == a[p + n]) {
          maxi = a[i + n];
        }
      }
    }
  }
  for (int i = 0; i < ansf.size(); i++) {
    cout << ansf[i] << " ";
  }
  for (int i = 0; i < ansf.size(); i++) {
    cout << ansb[i] << " ";
  }
  cout << endl;
}
