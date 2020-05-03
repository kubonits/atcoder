#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#define MOD 1000000007
using namespace std;
typedef unsigned long long ll;
ll a[500][500];
ll h[500][64], w[500][64];
int main() {
  int n;
  int s[500], t[500];
  ll u[500], v[500];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> u[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (s[i] == 0 && t[j] == 0) {
        a[i][j] = (u[i] | v[j]);
        for (int k = 0; k < 64; k++) {
          if ((((ll)1 << k) & a[i][j]) == 0) {
            h[i][k] = 1;
            w[j][k] = 1;
          }
        }
      } else if (s[i] == 1 && t[i] == 1) {
        a[i][j] = (u[i] & v[j]);
        for (int k = 0; k < 64; k++) {
          if ((((ll)1 << k) & a[i][j])) {
            h[i][k] = 1;
            w[j][k] = 1;
          }
        }
      } else if (s[i] == 0) {
        a[i][j] = u[i];
        if ((u[i] | t[j]) > t[j]) {
          cout << -1 << endl;
          return 0;
        }
        for (int k = 0; k < 64; k++) {
          if ((((ll)1 << k) & a[i][j])) {
            w[j][k] = 1;
          }
        }
      } else if (t[j] == 0) {
        a[i][j] = t[i];
        if ((u[i] | t[j]) > u[i]) {
          cout << -1 << endl;
        }
        for (int k = 0; k < 64; k++) {
          if ((((ll)1 << k) & a[i][j])) {
            h[i][k] = 1;
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == 1) {
      for (int j = 0; j < 64; j++) {
        if ((u[i] & ((ll)1 << j)) && h[i][j] == 0) {
          for (int k = 0; k < n; k++) {
            if (t[k] == 0 && w[k][j] == 1) {
              a[i][k] += ((ll)1 << j);
              h[i][j] = 1;
              break;
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (t[i] == 1) {
      for (int j = 0; j < 64; j++) {
        if ((v[i] & ((ll)1 << j)) && w[i][j] == 0) {
          for (int k = 0; k < n; k++) {
            if (s[k] == 0 && h[k][j] == 1) {
              a[i][k] += ((ll)1 << j);
              w[i][j] = 1;
              break;
            }
          }
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}