#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, x, m, l[10], r[10], s[10], a[6], y = 1, z;
  vector<int> v;
  v.push_back(-1);
  cin >> n >> x >> m;
  for (int i = 0; i < m; i++) {
    cin >> l[i] >> r[i] >> s[i];
    l[i]--;
    r[i]--;
  }
  for (int i = 0; i < n; i++) {
    y *= 11;
  }
  for (int i = 0; i < y; i++) {
    int flag = 1;
    z = i;
    for (int j = 0; j < n; j++) {
      a[j] = z % 11;
      z /= 11;
      if (a[j] > x) {
        flag = 0;
      }
    }
    for (int j = 0; j < m; j++) {
      z = 0;
      for (int k = l[j]; k <= r[j]; k++) {
        z += a[k];
      }
      if (z != s[j]) {
        flag = 0;
        break;
      }
    }
    if (flag) {
      z = 0;
      for (int j = 0; j < n; j++) {
        z += a[j];
      }
      for (int j = 0; j < v.size(); j++) {
        z -= v[j];
      }
      if (z > 0) {
        v.resize(n);
        for (int j = 0; j < n; j++) {
          v[j] = a[j];
        }
      }
    }
  }
  for (int i = 0; i < v.size(); i++) {
    cout << v[i];
    if (i < v.size() - 1) {
      cout << " ";
    } else {
      cout << endl;
    }
  }
}