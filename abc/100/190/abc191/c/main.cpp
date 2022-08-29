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
  int h, w, ans = 0;
  cin >> h >> w;
  vector<string> v(h + 2);
  string s(w + 2, '.');
  v[0] = v[1] = s;
  for (int i = 0; i < h; i++) {
    cin >> s;
    v[i + 1] = "." + s + ".";
  }
  for (int i = 0; i < h + 1; i++) {
    for (int j = 0; j < w + 1; j++) {
      int cnt = 0;
      if (v[i][j] == '#') {
        cnt++;
      }
      if (v[i][j + 1] == '#') {
        cnt++;
      }
      if (v[i + 1][j] == '#') {
        cnt++;
      }
      if (v[i + 1][j + 1] == '#') {
        cnt++;
      }
      if (cnt % 2) {
        ans++;
      }
    }
  }
  cout << ans << endl;
}
