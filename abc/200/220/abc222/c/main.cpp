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
  vector<string> s(2 * n);
  vector<pair<int, int> > v(2 * n);
  for (int i = 0; i < 2 * n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < 2 * n; i++) {
    v[i] = {0, i};
  }
  for (int i = 0; i < m; i++) {
    sort(v.begin(), v.end());
    for (int j = 0; j < n; j++) {
      if (s[v[2 * j].second][i] == 'G' && s[v[2 * j + 1].second][i] == 'C' ||
          s[v[2 * j].second][i] == 'C' && s[v[2 * j + 1].second][i] == 'P' ||
          s[v[2 * j].second][i] == 'P' && s[v[2 * j + 1].second][i] == 'G') {
        v[2 * j].first--;
      } else if (s[v[2 * j].second][i] != s[v[2 * j + 1].second][i]) {
        v[2 * j + 1].first--;
      }
    }
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < 2 * n; i++) {
    cout << v[i].second + 1 << endl;
  }
}
