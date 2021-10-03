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
  int n;
  string x;
  map<char, ll> m;
  cin >> x >> n;
  vector<string> s(n);
  vector<pair<ll, int> > v;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < 26; i++) {
    m.insert({x[i], i + 1LL});
  }
  for (int i = 0; i < n; i++) {
    ll cnt = 0LL;
    for (int j = 0; j < s[i].length(); j++) {
      cnt *= 27LL;
      cnt += m[s[i][j]];
    }
    for (int j = s[i].length(); j < 10; j++) {
      cnt *= 27LL;
    }
    v.push_back({cnt, i});
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    cout << s[v[i].second] << endl;
  }
}
