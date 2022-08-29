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
  int n, left = 0, right;
  string s;
  cin >> n >> s;
  vector<vector<int> > a(26);
  for (int i = 0; i < n; i++) {
    a[s[i] - 'a'].push_back(i);
  }
  right = n;
  for (int i = 0; i < 26; i++) {
    while (!a[i].empty()) {
      while (s[left] - 'a' <= i && left < n) {
        left++;
      }
      if (a[i].back() > left && a[i].back() <= right) {
        s[a[i].back()] ^= s[left];
        s[left] ^= s[a[i].back()];
        s[a[i].back()] ^= s[left];
        right = a[i].back();
      }
      a[i].pop_back();
    }
  }
  cout << s << endl;
}
