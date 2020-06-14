#include <iostream>
using namespace std;
typedef long long ll;
int main() {
  ll n, k, num = 0LL, ans = 0LL;
  cin >> n >> k;
  while (num < n) {
    num += (2LL * num + 1LL) * k;
    ans++;
  }
  cout << ans << endl;
}