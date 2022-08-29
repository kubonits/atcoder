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
  int h, w, ans = 1;
  cin >> h >> w;
  vector<string> s(h);
  queue<pair<int, int> > q;
  set<pair<int, int> > se;
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }
  q.push({0, 0});
  se.insert({0, 0});
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    ans = max(ans, x + y + 1);
    if (x != h - 1 && s[x + 1][y] == '.' && se.find({x + 1, y}) == se.end()) {
      q.push({x + 1, y});
      se.insert({x + 1, y});
    }
    if (y != w - 1 && s[x][y + 1] == '.' && se.find({x, y + 1}) == se.end()) {
      q.push({x, y + 1});
      se.insert({x, y + 1});
    }
  }
  cout << ans << endl;
}
