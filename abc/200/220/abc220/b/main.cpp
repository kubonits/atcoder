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

ll f(string s, int k) {
  ll res = 0LL;
  for (int i = 0; i < s.length(); i++) {
    res *= k;
    res += s[i] - '0';
  }
  return res;
}

int main() {
  ll k;
  string a, b;
  cin >> k >> a >> b;
  cout << f(a, k) * f(b, k) << endl;
}
