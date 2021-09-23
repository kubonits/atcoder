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
  int n, t;
  string s;
  vector<pair<int, string> > v;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s >> t;
    v.push_back({t, s});
  }
  sort(v.begin(), v.end());
  v.pop_back();
  cout << v.back().second << endl;
}
