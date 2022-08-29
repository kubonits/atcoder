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
  int n, u, v, x = 0;
  vector<int> p(9);
  map<int, int> m;
  queue<int> q;
  set<int> s[10];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> u >> v;
    s[u].insert(v);
    s[v].insert(u);
  }
  for (int i = 1; i <= 8; i++) {
    cin >> p[i];
    x *= 10;
    x += p[i];
  }
  q.push(x);
  m[x] = 0;
  while (!q.empty()) {
    int num = q.front();
    q.pop();
    if (num == 12345678) {
      cout << m[num] << endl;
      return 0;
    }
    int x = num;
    vector<int> f(10);
    for (int i = 0; i < 8; i++) {
      p[8 - i] = x % 10;
      f[x % 10] = 1;
      x /= 10;
    }
    for (int i = 1; i <= 9; i++) {
      if (f[i] == 0) {
        v = i;
        break;
      }
    }
    for (int i = 1; i <= 8; i++) {
      if (s[v].find(p[i]) != s[v].end()) {
        u = num + pow(10, (8 - i)) * (v - p[i]);
        // cout << u << endl;
        if (m.find(u) == m.end()) {
          m[u] = m[num] + 1;
          q.push(u);
        }
      }
    }
  }
  cout << -1 << endl;
}
