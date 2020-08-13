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
  int n, ans = 0;
  deque<char> d;
  string s;
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; i++) {
    d.push_back(s[i]);
  }
  while (!d.empty()) {
    while (!d.empty() && d[0] == 'R') {
      d.pop_front();
    }
    while (!d.empty() && d.back() == 'W') {
      d.pop_back();
    }
    if (d.empty()) {
      break;
    }
    if (d[0] == 'W' && d.back() == 'R') {
      ans++;
      d.pop_front();
      d.pop_back();
    }
  }
  cout << ans << endl;
}