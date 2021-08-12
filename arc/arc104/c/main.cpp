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

bool calc(int l, int r, vector<pair<int, int> > &v) {
  int x = r - l + 1;
  x /= 2;
  for (int i = 0; i < x; i++) {
    if (v[l + i].first == -1) {
      return false;
    }
    if (v[i + l + x].first == 1) {
      return false;
    }
    if (v[i + l].first == 1 && v[i + l].second != -1 &&
        v[i + l].second != i + l + x) {
      return false;
    }
    if (v[i + l + x].first == -1 && v[i + l + x].second != -1 &&
        v[i + l + x].second != i + l) {
      return false;
    }
    if (v[i + l].first == 1 && v[i + l + x].first == -1 &&
        (v[i + l].second == -1 || v[i + l + x].second == -1)) {
      return false;
    }
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1), dp(2 * n + 1);
  vector<pair<int, int> > v(2 * n + 1);
  set<int> s;
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    if (a[i] != -1 && b[i] != -1) {
      v[a[i]].first = 1;
      v[a[i]].second = b[i];
      v[b[i]].first = -1;
      v[b[i]].second = a[i];
      if (a[i] >= b[i]) {
        cout << "No" << endl;
        return 0;
      }
      if (s.find(a[i]) != s.end()) {
        cout << "No" << endl;
        return 0;
      } else {
        s.insert(a[i]);
      }
      if (s.find(b[i]) != s.end()) {
        cout << "No" << endl;
        return 0;
      } else {
        s.insert(b[i]);
      }
    } else if (a[i] != -1) {
      v[a[i]] = {1, -1};
      if (s.find(a[i]) != s.end()) {
        cout << "No" << endl;
        return 0;
      } else {
        s.insert(a[i]);
      }
    } else if (b[i] != -1) {
      v[b[i]] = {-1, -1};
      if (s.find(b[i]) != s.end()) {
        cout << "No" << endl;
        return 0;
      } else {
        s.insert(b[i]);
      }
    }
  }
  for (int i = 1; i < 2 * n; i++) {
    for (int j = i + 1; j <= 2 * n; j += 2) {
      if (calc(i, j, v) && dp[i - 1] == 1) {
        dp[j] = 1;
      }
    }
  }
  if (dp[2 * n]) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}