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

int g[400][400], dp[400][400];

int main() {
  int n, m, a, b;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    a--;
    b--;
    g[a][b] = 1;
    g[b][a] = 1;
  }
  for (int i = 0; i < 2 * n - 1; i++) {
    if (g[i][i + 1]) {
      dp[i][i + 1] = 1;
    }
  }
  for (int k = 3; k < 2 * n; k += 2) {
    for (int i = 0; i + k < 2 * n; i++) {
      if (dp[i + 1][i + k - 1] && g[i][i + k]) {
        dp[i][i + k] = dp[i + 1][i + k - 1];
      }
      for(int j=1;j<k;j+=2){
        if(dp[i][i+j]&&dp[i+j+1][i+k]){
          
        }
      }
    }
  }
}