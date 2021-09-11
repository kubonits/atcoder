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

int k, a[8] = {};
set<string> se;
string s;

void dfs(string t, int x) {
  if (x == s.length()) {
    if (se.find(t) == se.end()) {
      se.insert(t);
      if (se.size() == k) {
        cout << t << endl;
      }
    }
    return;
  }
  for (int i = 0; i < s.length(); i++) {
    if (a[i] == 0) {
      a[i] = 1;
      dfs(t + s[i], x + 1);
      a[i] = 0;
    }
  }
}

int main() {
  cin >> s >> k;
  sort(s.begin(), s.end());
  dfs("", 0);
}