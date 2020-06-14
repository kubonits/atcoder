#include <algorithm>
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

int main() {
  ll n, a, ans;
  cin >> n;
  vector<ll> v(1000000 + 10);
  for (int i = 0; i < 1000010; i++) {
    v[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> a;
    v[a]++;
  }
  ans = 0LL;
  for (int i = 1; i <= 1000000; i++) {
    if (v[i]) {
      if (v[i] == 1) {
        ans++;
      }
      for (int j = i + i; j <= 1000000; j += i) {
        v[j] = 0;
      }
    }
  }
  cout << ans << endl;
}