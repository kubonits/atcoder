#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
int main() {
  int n, m;
  ll a[100][100], cnt, ans = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = i + 1; j < m; j++) {
      cnt = 0;
      for (int k = 0; k < n; k++) {
        cnt += max(a[k][i], a[k][j]);
      }
      ans = max(ans, cnt);
    }
  }
  cout << ans << endl;
}