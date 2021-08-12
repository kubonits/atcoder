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
  int n, flag = 0;
  map<string, int> se;
  string s, t = "";
  cin >> s;
  n = s.length();
  for (int i = 0; i < n; i++) {
    t += s[i];
    if (flag == 0) {
      flag = 1;
      t.back() += 'a' - 'A';
    } else if (flag == 1 && s[i] >= 'A' && s[i] <= 'Z') {
      flag = 0;
      t.back() += 'a' - 'A';
      se[t]++;
      t = "";
    }
  }
  for (auto it = se.begin(), e = se.end(); it != e; it++) {
    for (int i = 0; i < it->second; i++) {
      t = it->first;
      t[0] += 'A' - 'a';
      t.back() += 'A' - 'a';
      cout << t;
    }
  }
  cout << endl;
}