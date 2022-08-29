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
  int n;
  string s;
  cin >> n >> s;
  vector<int> v(3 * n), sumx(3 * n + 1), sumy(3 * n + 1), sumz(3 * n + 1);
  vector<string> vs = {"ABC", "ACB", "BAC", "BCA", "CAB", "CBA"};
  for (int k = 0; k < 6; k++) {
    int x = 0, y = n, z = 2 * n;
    while (x < n && y < 2 * n && z < 3 * n) {
      while (x < n && (v[x] != 0 || s[x] != vs[k][0])) {
        x++;
      }
      while (y < 2 * n && (v[y] != 0 || s[y] != vs[k][1])) {
        y++;
      }
      while (z < 3 * n && (v[z] != 0 || s[z] != vs[k][2])) {
        z++;
      }
      if (x < n && y < 2 * n && z < 3 * n) {
        v[x] = v[y] = v[z] = k + 1;
      }
    }
  }
  for (int i = 0; i < 3 * n; i++) {
    cout << v[i];
  }
  cout << endl;
}