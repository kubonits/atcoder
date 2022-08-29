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
  int cnt = 100000;
  while (cnt--) {
    int n, mini = 1000000000, maxi = 0;
    n = rand() % 10 + 1;
    vector<int> a(2 * n);
    map<int, int> m, ma;
    for (int i = 0; i < 2 * n; i++) {
      a[i] = rand() % 1000 + 1;
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
        if (a[i] == v[i] && a[i] <= a[p + n] && (a[i] == mini || a[i] < maxi)) {
          ansf.push_back(a[i]);
          ansb.push_back(a[i + n]);
          maxi = max(maxi, a[i + n]);
        }
      }
    }

    vector<int> x;
    for (int i = 0; i < ansf.size(); i++) {
      x.push_back(ansf[i]);
    }
    for (int i = 0; i < ansf.size(); i++) {
      x.push_back(ansb[i]);
    }
    for (int i = 1; i < (1 << n); i++) {
      vector<int> bb, bf;
      int flag = 0;
      for (int j = 0; j < n; j++) {
        if (i & (1 << j)) {
          bf.push_back(a[j]);
          bb.push_back(a[j + n]);
        }
      }
      vector<int> y;
      for (int j = 0; j < bf.size(); j++) {
        y.push_back(bf[j]);
      }
      for (int j = 0; j < bf.size(); j++) {
        y.push_back(bb[j]);
      }
      for (int j = 0; j < min(x.size(), y.size()); j++) {
        if (x[j] > y[j]) {
          flag = 1;
          break;
        }
        if (x[j] < y[j]) {
          flag = -1;
          break;
        }
      }
      if (flag == 0 && x.size() > y.size()) {
        flag = 1;
      }
      if (flag == 1) {
        cout << n << endl;
        for (int i = 0; i < 2 * n; i++) {
          cout << a[i] << "\t";
        }
        cout << endl;
        for (int j = 0; j < x.size(); j++) {
          cout << x[j] << '\t';
        }
        cout << endl;
        for (int j = 0; j < y.size(); j++) {
          cout << y[j] << '\t';
        }
        cout << endl;
        cout << ma[mini] << endl;
        return 0;
      }
    }
  }
}
