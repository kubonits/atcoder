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
  int n;
  cin >> n;
  vector<vector<int> > v(n, vector<int>(n));
  v[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i + 1; j++) {
      if (i) {
        if (j) {
          v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
        } else {
          v[i][j] = 1;
        }
      }
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
}
