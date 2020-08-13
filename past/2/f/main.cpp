#include <algorithm>
#include <cmath>
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

int main() {
  int n, a, b, ans = 0, p = 0;
  cin >> n;
  vector<pair<int, int> > v;
  priority_queue<int> q;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    v.push_back({a, b});
  }
  sort(v.begin(), v.end());
  for (int i = 1; i <= n; i++) {
    while (p < n && v[p].first <= i) {
      q.push(v[p].second);
      p++;
    }
    ans += q.top();
    q.pop();
    cout << ans << endl;
  }
}