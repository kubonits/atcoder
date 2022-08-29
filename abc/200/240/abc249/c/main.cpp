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
#define MOD2 998244353
using namespace std;
typedef long long ll;
#include <cstring>

int main() {
  int n, k, ans = 0;
  cin >> n >> k;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < (1 << n); i++) {
    vector<int> v(26);
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        for (int l = 0; l < s[j].length(); l++) {
          v[s[j][l] - 'a']++;
        }
      }
    }
    int cnt = 0;
    for (int j = 0; j < 26; j++) {
      if (v[j] == k) {
        cnt++;
      }
    }
    ans = max(ans, cnt);
  }
  cout << ans << endl;
}
