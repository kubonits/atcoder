#include <iostream>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int main() {
  int n, a[100000], b[3] = {};
  ll cnt, ans = 1LL;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt = 0LL;
    for (int j = 0; j < 3; j++) {
      if (a[i] == b[j]) {
        cnt++;
      }
    }
    ans *= cnt;
    ans %= MOD;
    for (int j = 0; j < 3; j++) {
      if (a[i] == b[j]) {
        b[j]++;
        break;
      }
    }
  }
  cout << ans << endl;
}