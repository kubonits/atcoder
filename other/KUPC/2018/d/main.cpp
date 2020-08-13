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
  int l, r, mid, f = 0, cnt = 1;
  string s, s2;
  l = 1;
  r = 1000000001;
  cout << "? 2" << endl;
  flush(cout);
  cin >> s;
  if (s == "odd") {
    f = 1;
  }
  while (1) {
    cnt++;
    mid = (l + r + 1) / 2 | 1;
    if (l >= mid || mid >= r) {
      break;
    }
    cout << "? " << mid << endl;
    flush(cout);
    cin >> s2;
    if (s == s2) {
      r = mid;
    } else {
      l = mid;
    }
  }
  if (l % 2 != f) {
    l++;
  }
  cout << "! " << l << endl;
}