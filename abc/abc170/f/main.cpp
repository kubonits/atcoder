#include <algorithm>
#include <climits>
#include <cmath>
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
const int MAX_N = 1 << 17;

int h, w, H, W;
vector<vector<int> > datw, dath;

void init(int h_, int w_) {
  h = 1;
  while (h < h_) {
    h *= 2;
  }
  w = 1;
  while (w < w_) {
    w *= 2;
  }
  for (int i = 0; i < H; i++) {
    dath[i].resize(2 * w + 1);
    for (int j = 0; j < 2 * w - 1; j++) {
      dath[i][j] = 100000000;
    }
  }
  for (int i = 0; i < W; i++) {
    datw[i].resize(2 * h + 1);
    for (int j = 0; j < 2 * h + 1; j++) {
      datw[i][j] = 100000000;
    }
  }
}

void updateh(int k, int a, int x) {
  k += w - 1;
  dath[x][k] = a;
  while (k > 0) {
    k = (k - 1) / 2;
    dath[x][k] = min(dath[x][k * 2 + 1], dath[x][k * 2 + 2]);
  }
}

void updatew(int k, int a, int x) {
  k += h - 1;
  datw[x][k] = a;
  while (k > 0) {
    k = (k - 1) / 2;
    datw[x][k] = min(datw[x][k * 2 + 1], datw[x][k * 2 + 2]);
  }
}

int queryh(int a, int b, int k, int l, int r, int x) {
  if (r <= a || b <= l) {
    return INT_MAX;
  }
  if (a <= l && r <= b) {
    return dath[x][k];
  } else {
    int vl = queryh(a, b, k * 2 + 1, l, (l + r) / 2, x);
    int vr = queryh(a, b, k * 2 + 2, (l + r) / 2, r, x);
    return min(vl, vr);
  }
}

int queryw(int a, int b, int k, int l, int r, int x) {
  if (r <= a || b <= l) {
    return INT_MAX;
  }
  if (a <= l && r <= b) {
    return datw[x][k];
  } else {
    int vl = queryw(a, b, k * 2 + 1, l, (l + r) / 2, x);
    int vr = queryw(a, b, k * 2 + 2, (l + r) / 2, r, x);
    return min(vl, vr);
  }
}

int main() {
  int k, sx, sy, gx, gy;
  int dx[4] = {-1, 0, 0, 1};
  int dy[4] = {0, -1, 1, 0};
  queue<pair<int, int> > q;
  vector<vector<int> > f, l, r, u, d;
  cin >> h >> w >> k >> sx >> sy >> gx >> gy;
  H = h;
  W = w;
  dath.resize(h + 1);
  datw.resize(w + 1);
  f.resize(h);
  d.resize(h);
  u.resize(h);
  r.resize(h);
  l.resize(h);
  for (int i = 0; i < h; i++) {
    f[i].resize(w);
    l[i].resize(w);
    r[i].resize(w);
    u[i].resize(w);
    d[i].resize(w);
    for (int j = 0; j < w; j++) {
      f[i][j] = 0;
      l[i][j] = j;
      r[i][j] = j;
      u[i][j] = i;
      d[i][j] = i;
    }
  }
  init(h, w);
  sx--;
  sy--;
  gx--;
  gy--;
  updateh(sy, 0, sx);
  updatew(sx, 0, sy);
  q.push({sx, sy});
  f[sx][sy] = 1;
  vector<string> s(h + 10);
  for (int i = 0; i < H; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (s[i][j] != '@' && j && s[i][j - 1] != '@') {
        l[i][j] = max(l[i][j - 1], j - k);
      }
    }
    for (int j = W - 2; j >= 0; j--) {
      if (s[i][j] != '@' && s[i][j + 1] != '@') {
        r[i][j] = min(r[i][j + 1], j + k);
      }
    }
  }
  for (int j = 0; j < W; j++) {
    for (int i = 0; i < H; i++) {
      if (s[i][j] != '@' && i && s[i - 1][j] != '@') {
        u[i][j] = max(u[i - 1][j], i - k);
      }
    }
    for (int i = H - 2; i >= 0; i--) {
      if (s[i][j] != '@' && s[i + 1][j] != '@') {
        d[i][j] = min(d[i + 1][j], i + k);
      }
    }
  }
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      if (x + dx[i] >= 0 && x + dx[i] < H && y + dy[i] >= 0 && y + dy[i] < W &&
          s[x + dx[i]][y + dy[i]] != '@') {
        int z = min(queryh(l[x + dx[i]][y + dy[i]], r[x + dx[i]][y + dy[i]] + 1,
                           0, 0, w, x + dx[i]),
                    queryw(u[x + dx[i]][y + dy[i]], d[x + dx[i]][y + dy[i]] + 1,
                           0, 0, h, y + dy[i]));
        if (queryh(y + dy[i], y + dy[i] + 1, 0, 0, w, x + dx[i]) > z + 1) {
          updateh(y + dy[i], z + 1, x + dx[i]);
          updatew(x + dx[i], z + 1, y + dy[i]);
          q.push({x + dx[i], y + dy[i]});
        }
      }
    }
  }
  if (queryh(gy, gy + 1, 0, 0, w, gx) != 100000000) {
    cout << queryh(gy, gy + 1, 0, 0, w, gx) << endl;
  } else {
    cout << -1 << endl;
  }
}