#include <iostream>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int main() {
  ll n, cnt = 0LL, ans = 1LL;
  ll x[100000];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < n; i++) {
    cnt++;
    if (x[i] < cnt * 2LL - 1LL) {
      ans *= cnt;
      ans %= MOD;
      cnt--;
    }
  }
  while (cnt) {
    ans *= cnt;
    ans %= MOD;
    cnt--;
  }
  cout << ans << endl;
}