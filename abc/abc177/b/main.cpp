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

int main() {
  int ans = 1000, cnt;
  string s, t;
  cin >> s >> t;
  for (int i = 0; i <= s.length() - t.length(); i++) {
    cnt = 0;
    for (int j = 0; j < t.length(); j++) {
      if (s[i + j] != t[j]) {
        cnt++;
      }
    }
    ans = min(ans, cnt);
  }
  cout << ans << endl;
}