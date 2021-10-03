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
  int n, q, x, a, b, f = 0;
  string s, t;
  cin >> n >> s >> q;
  t = s.substr(n);
  s = s.substr(0, n);
  while (q--) {
    cin >> x >> a >> b;
    if (x == 1) {
      a--;
      b--;
      if (!f && b < n) {
        char temp = s[a];
        s[a] = s[b];
        s[b] = temp;
      } else if (!f && a >= n) {
        a -= n;
        b -= n;
        char temp = t[a];
        t[a] = t[b];
        t[b] = temp;
      } else if (!f) {
        b -= n;
        char temp = s[a];
        s[a] = t[b];
        t[b] = temp;
      } else if (b < n) {
        char temp = t[a];
        t[a] = t[b];
        t[b] = temp;
      } else if (a >= n) {
        a -= n;
        b -= n;
        char temp = s[a];
        s[a] = s[b];
        s[b] = temp;
      } else {
        b -= n;
        char temp = t[a];
        t[a] = s[b];
        s[b] = temp;
      }
    } else {
      f ^= 1;
    }
  }
  cout << (!f ? s + t : t + s) << endl;
}
