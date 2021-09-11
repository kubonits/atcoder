#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  int n;
  ll a[100000], ans = 0LL;
  vector<ll> v;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i == 0 || a[i] <= a[i - 1]) {
      v.push_back(i);
    }
  }
  v.push_back(n);
  for (int i = 0; i < v.size() - 1; i++) {
    ans += (v[i + 1] - v[i]) * (v[i + 1] - v[i] + 1LL) / 2L;
  }
  cout << ans << endl;
}