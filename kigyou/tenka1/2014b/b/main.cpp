#include <iostream>
#include <string>
using namespace std;
#define MOD 1000000007
typedef long long ll;
int main() {
  int n, l;
  ll dp[1001] = {};
  string s, t[100];
  cin >> n >> s;
  l = s.length();
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  dp[0] = 1LL;
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < n; j++) {
      if (l - i >= t[j].length() && s.substr(i, t[j].length()) == t[j]) {
        dp[i + t[j].length()] += dp[i];
        dp[i + t[j].length()] %= MOD;
      }
    }
  }
  cout << dp[l] << endl;
}