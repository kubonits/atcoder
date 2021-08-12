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
  int n, q, a, b, c;
  cin >> n >> q;
  set<int> s;
  vector<vector<int> > v(n);
  for (int i = 0; i < n; i++) {
    v[i].resize(n);
  }
  for (int i = 0; i < q; i++) {
    cin >> a;
    if (a == 1) {
      cin >> b >> c;
      b--;
      c--;
      v[b][c] = 1;
    } else if (a == 2) {
      cin >> b;
      b--;
      for (int j = 0; j < n; j++) {
        if (v[j][b] == 1) {
          v[b][j] = 1;
        }
      }
    } else {
      cin >> b;
      b--;
      s.clear();
      for (int j = 0; j < n; j++) {
        if (v[b][j] == 1) {
          s.insert(j);
        }
      }
      for (auto &&x : s) {
        for (int k = 0; k < n; k++) {
          if (k != b && v[x][k] == 1) {
            v[b][k] = 1;
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << (v[i][j] ? 'Y' : 'N');
    }
    cout << endl;
  }
}