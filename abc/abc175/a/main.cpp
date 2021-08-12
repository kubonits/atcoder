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
  string s;
  cin >> s;
  for (int i = 0; i < 3; i++) {
    if (s[i] == 'R') {
      ans = 1;
    }
  }
  for (int i = 0; i < 2; i++) {
    if (s.substr(i, 2) == "RR") {
      ans = 2;
    }
  }
  if (s == "RRR") {
    ans = 3;
  }
  cout << ans << endl;
}