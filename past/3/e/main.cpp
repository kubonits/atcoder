#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
  int n, m, q, a, b, c[201], d;
  vector<int> v[201];
  cin >> n >> m >> q;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  for (int i = 0; i < q; i++) {
    cin >> a >> b;
    if (a == 1) {
      cout << c[b] << endl;
      for (int j = 0; j < v[b].size(); j++) {
        c[v[b][j]] = c[b];
      }
    } else {
      cout << c[b] << endl;
      cin >> a;
      c[b] = a;
    }
  }
}