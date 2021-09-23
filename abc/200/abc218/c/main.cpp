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

int n;

vector<string> leftup(vector<string> s) {
  vector<string> res(n);
  int left = n, up = n;
  for (int i = 0; i < n; i++) {
    res[i].resize(n);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (s[i][j] == '#') {
        left = min(left, j);
        up = min(up, i);
      }
      res[i][j] = '.';
    }
  }
  for (int i = 0; i + up < n; i++) {
    for (int j = 0; j + left < n; j++) {
      res[i][j] = s[i + up][j + left];
    }
  }
  return res;
}

vector<string> spin(vector<string> s) {
  vector<string> res(n);
  int left = n, up = n;
  for (int i = 0; i < n; i++) {
    res[i].resize(n);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      res[i][j] = s[n - j - 1][i];
    }
  }
  return res;
}

int main() {
  cin >> n;
  vector<string> s(n), t(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  s = leftup(s);
  t = leftup(t);
  if (s == t) {
    cout << "Yes" << endl;
    return 0;
  }
  for (int i = 0; i < 3; i++) {
    s = spin(s);
    s = leftup(s);
    if (s == t) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
