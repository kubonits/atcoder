#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;

vector<int> g[100001];
ll dp[100001][2];

void dfs(int x, int y) {
  dp[x][0] = dp[x][1] = 1LL;
  for (int i = 0; i < g[x].size(); i++) {
    if (g[x][i] != y) {
      dfs(g[x][i], x);
      dp[x][0] *= (dp[g[x][i]][0] + dp[g[x][i]][1]) % MOD;
      dp[x][0] %= MOD;
      dp[x][1] *= (dp[g[x][i]][0]) % MOD;
      dp[x][1] %= MOD;
    }
  }
}

int main() {
  int n, a, b;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(1, -1);
  cout << (dp[1][0] + dp[1][1]) % MOD << endl;
}