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
  int n, q, a, b, c;
  cin >> n >> q;
  vector<pair<int, int> > v(n + 1, {-1, -1});
  for (int i = 0; i < q; i++) {
    cin >> a;
    if (a == 1) {
      cin >> b >> c;
      v[b].second = c;
      v[c].first = b;
    } else if (a == 2) {
      cin >> b >> c;
      v[b].second = -1;
      v[c].first = -1;
    } else {
      cin >> b;
      while (v[b].first != -1) {
        b = v[b].first;
      }
      queue<int> q;
      while (v[b].second != -1) {
        q.push(b);
        b = v[b].second;
      }
      q.push(b);
      cout << q.size() << " ";
      while (!q.empty()) {
        cout << q.front();
        q.pop();
        cout << (q.empty() ? "\n" : " ");
      }
    }
  }
}
