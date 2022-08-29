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
  int n, m;
  cin >> n >> m;
  vector<vector<int> > v(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> v[i][j];
    }
  }
  for (int i = 0; i < m - 1; i++) {
    if (v[0][i + 1] - v[0][i] != 1 ||
        (v[0][i + 1] - 1) % 7 - (v[0][i] - 1) % 7 != 1) {
      cout << "No" << endl;
      return 0;
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (v[i][j] - v[i - 1][j] != 7) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
}
