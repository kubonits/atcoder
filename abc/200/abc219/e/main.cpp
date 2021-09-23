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

int a[4][4], b[4][4];

int n, m;

struct unionfind {
  int parent;
  int node;
  int edge;
};
unionfind g[100001];

void init() {
  for (int i = 0; i <= 16; i++) {
    g[i].parent = i;
    g[i].node = 1;
    g[i].edge = 0;
  }
}

int ufind(int x) {
  if (x == g[x].parent) {
    return x;
  }
  int res = ufind(g[x].parent);
  g[x].node = g[res].node;
  g[x].edge = g[res].edge;
  g[x].parent = res;
  return res;
}

void umerge(int x, int y) {
  if (x > y) {
    x ^= y;
    y ^= x;
    x ^= y;
  }
  g[x].node += g[y].node;
  g[x].edge += g[y].edge + 1;
  g[y].parent = x;
}

void dfs(int x, int y) {
  b[x][y] = 0;
  if (x - 1 >= 0 && b[x - 1][y]) {
    dfs(x - 1, y);
  }
  if (x + 1 < 4 && b[x + 1][y]) {
    dfs(x + 1, y);
  }
  if (y - 1 >= 0 && b[x][y - 1]) {
    dfs(x, y - 1);
  }
  if (y + 1 < 4 && b[x][y + 1]) {
    dfs(x, y + 1);
  }
}

bool check() {
  vector<int> v = {0, 1, 2, 3, 4, 7, 8, 11, 12, 13, 14, 15};
  init();
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (b[i][j] == 0) {
        if (i - 1 >= 0 && !b[i - 1][j]) {
          int x = ufind((i - 1) * 4 + j);
          int y = ufind(i * 4 + j);
          if (x != y) {
            umerge(x, y);
          }
        }
        if (i + 1 < 4 && !b[i + 1][j]) {
          int x = ufind((i + 1) * 4 + j);
          int y = ufind(i * 4 + j);
          if (x != y) {
            umerge(x, y);
          }
        }
        if (j - 1 >= 0 && !b[i][j - 1]) {
          int x = ufind((i)*4 + j - 1);
          int y = ufind(i * 4 + j);
          if (x != y) {
            umerge(x, y);
          }
        }
        if (j + 1 < 4 && !b[i][j + 1]) {
          int x = ufind((i)*4 + j + 1);
          int y = ufind(i * 4 + j);
          if (x != y) {
            umerge(x, y);
          }
        }
      }
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (b[i][j] == 0) {
        int flag = 0;
        for (int k = 0; k < v.size(); k++) {
          if (ufind(i * 4 + j) == ufind(v[k])) {
            flag = 1;
          }
        }
        if (flag == 0) {
          return false;
        }
      }
    }
  }
  return true;
}

int main() {
  int ans = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < (1 << 16); i++) {
    // cout << i << endl;
    int flag = 1, cnt = 0;
    for (int j = 0; j < 16; j++) {
      if (i & (1 << j)) {
        b[j / 4][j % 4] = 1;
      } else {
        b[j / 4][j % 4] = 0;
      }
      if (a[j / 4][j % 4] && !b[j / 4][j % 4]) {
        flag = 0;
      }
    }
    if (!check()) {
      flag = 0;
    }
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        if (b[j][k]) {
          dfs(j, k);
          cnt++;
        }
      }
    }
    if (cnt == 1 && flag == 1) {
      // cout << i << endl;
      ans++;
    }
  }
  cout << ans << endl;
}
