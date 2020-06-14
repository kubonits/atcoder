#include <iostream>
#include <vector>
using namespace std;
int n;
int h[100000], ans[100000], l[100000], r[100000];
int dfsl(int x) {
  if (l[x] == x) {
    return x;
  }
  return l[x] = dfsl(l[x]);
}

int dfsr(int x) {
  if (r[x] == x) {
    return x;
  }
  return r[x] = dfsr(r[x]);
}

int main() {
  cin >> n;
  vector<vector<int> > x(100001);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
    x[h[i]].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    l[i] = r[i] = i;
  }
  for (int i = 1; i <= 100000; i++) {
    for (int j = 0; j < x[i].size(); j++) {
      if (x[i][j] != 0 && h[x[i][j]] >= h[x[i][j] - 1]) {
        l[x[i][j]] = dfsl(l[x[i][j] - 1]);
        r[x[i][j] - 1] = dfsr(r[x[i][j]]);
      }
      if (x[i][j] != n - 1 && h[x[i][j]] >= h[x[i][j] + 1]) {
        l[x[i][j] + 1] = dfsl(l[x[i][j]]);
        r[x[i][j]] = dfsr(r[x[i][j] + 1]);
      }
    }
    for (int j = 0; j < x[i].size(); j++) {
      dfsl(x[i][j]);
      dfsr(x[i][j]);
      ans[x[i][j]] = r[x[i][j]] - l[x[i][j]];
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << endl;
  }
}