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
  int n, maxi = 0;
  string s, ans;
  map<string, int> m;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    m[s]++;
  }
  for (auto &&x : m) {
    if (x.second > maxi) {
      maxi = x.second;
      ans = x.first;
    }
  }
  cout << ans << endl;
}
