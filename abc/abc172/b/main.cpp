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
  int n, ans = 0;
  string s, t;
  cin >> s >> t;
  vector<int> v(n + 10);
  for (int i = 0; i < s.length(); i++) {
    if (s[i] != t[i]) {
      ans++;
    }
  }
  cout << ans << endl;
}