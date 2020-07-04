#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
  int n, k;
  string s;
  ll ans = 0;
  cin >> n >> k >> s;
  vector<int> v(n + 1);
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      v[i + 1] = v[i] + 1;
    } else {
      v[i + 1] = v[i] - 1;
    }
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < k; i++) {
    ans += v[n - i];
  }
  cout << ans << endl;
}