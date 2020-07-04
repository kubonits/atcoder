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
string s;
map<char, int> m;
int gx, gy, flag[4], a[4];

bool calc(int n) {
  if (gx == 0 && gy == 0) {
    return true;
  }
  if (n == 4) {
    int x = 0, y = 0;
    for (int i = 0; i < s.size(); i++) {
      if (a[m[s[i]]] == 0) {
        x--;
      } else if (a[m[s[i]]] == 1) {
        x++;
      } else if (a[m[s[i]]] == 2) {
        y--;
      } else if (a[m[s[i]]] == 3) {
        y++;
      }
      if (x == gx && y == gy) {
        return true;
      }
    }
    return false;
  }
  for (int i = 0; i < 4; i++) {
    if (flag[i] == 0) {
      flag[i] = 1;
      a[n] = i;
      if (calc(n + 1)) {
        return true;
      }
      flag[i] = 0;
    }
  }
  return false;
}

int main() {
  cin >> s >> gx >> gy;
  m.insert({'W', 0});
  m.insert({'X', 1});
  m.insert({'Y', 2});
  m.insert({'Z', 3});
  cout << (calc(0) ? "Yes" : "No") << endl;
}