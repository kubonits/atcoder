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
  ll a, x, y;
  string s;
  cin >> a >> s;
  x = 0;
  y = 0;
  for (int i = 0; i < s.length(); i++) {
    x *= a;
    x += s[s.length() - 1 - i] - 'a' + 1;
  }
}