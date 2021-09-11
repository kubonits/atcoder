#include <iostream>
#include <queue>
#define MOD 1000000007
using namespace std;

typedef long long ll;
ll dp[1000000], in[1000000], ans;
int h, w, a[1000][1000];
int main() {
  queue<int> q;
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      dp[i * w + j] = 1LL;
      if (i != 0 && a[i][j] > a[i - 1][j]) {
        in[i * w + j]++;
      }
      if (i != h - 1 && a[i][j] > a[i + 1][j]) {
        in[i * w + j]++;
      }
      if (j != 0 && a[i][j] > a[i][j - 1]) {
        in[i * w + j]++;
      }
      if (j != w - 1 && a[i][j] > a[i][j + 1]) {
        in[i * w + j]++;
      }
      if (in[i * w + j] == 0) {
        q.push(i * w + j);
      }
    }
  }
  while (!q.empty()) {
    int x = q.front() / w;
    int y = q.front() % w;
    ans += dp[q.front()];
    ans %= MOD;
    if (x != 0 && a[x][y] < a[x - 1][y]) {
      x--;
      dp[x * w + y] += dp[q.front()];
      dp[x * w + y] %= MOD;
      in[x * w + y]--;
      if (in[x * w + y] == 0) {
        q.push(x * w + y);
      }
      x++;
    }
    if (x != h - 1 && a[x][y] < a[x + 1][y]) {
      x++;
      dp[x * w + y] += dp[q.front()];
      dp[x * w + y] %= MOD;
      in[x * w + y]--;
      if (in[x * w + y] == 0) {
        q.push(x * w + y);
      }
      x--;
    }
    if (y != 0 && a[x][y] < a[x][y - 1]) {
      y--;
      dp[x * w + y] += dp[q.front()];
      dp[x * w + y] %= MOD;
      in[x * w + y]--;
      if (in[x * w + y] == 0) {
        q.push(x * w + y);
      }
      y++;
    }
    if (y != w - 1 && a[x][y] < a[x][y + 1]) {
      y++;
      dp[x * w + y] += dp[q.front()];
      dp[x * w + y] %= MOD;
      in[x * w + y]--;
      if (in[x * w + y] == 0) {
        q.push(x * w + y);
      }
      y--;
    }
    q.pop();
  }
  cout << ans << endl;
}