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

int h, w, a, b;
vector<vector<int> > v;

int dfs(int x, int y, int z) {
  if (x == h * w) {
    return 1;
  }
  int res = 0;
  if (v[x / w][x % w] != 0) {
    return dfs(x + 1, y, z);
  }
  if (v[x / w][x % w] == 0 && z < b) {
    v[x / w][x % w] = a + z + 1;
    res += dfs(x + 1, y, z + 1);
    v[x / w][x % w] = 0;
  }

  if (v[x / w][x % w] == 0 && x / w + 1 < h && v[x / w + 1][x % w] == 0 &&
      y < a) {
    v[x / w][x % w] = y + 1;
    v[x / w + 1][x % w] = y + 1;
    res += dfs(x + 1, y + 1, z);
    v[x / w][x % w] = 0;
    v[x / w + 1][x % w] = 0;
  }
  if (v[x / w][x % w] == 0 && x % w + 1 < w && v[x / w][x % w + 1] == 0 &&
      y < a) {
    v[x / w][x % w] = y + 1;
    v[x / w][x % w + 1] = y + 1;
    res += dfs(x + 1, y + 1, z);
    v[x / w][x % w] = 0;
    v[x / w][x % w + 1] = 0;
  }
  return res;
}

int main() {
  cin >> h >> w >> a >> b;
  v.resize(h);
  for (int i = 0; i < h; i++) {
    v[i].resize(w);
  }
  cout << dfs(0, 0, 0) << endl;
}
