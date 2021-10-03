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
  int n, m, k, a;
  cin >> n >> m;
  queue<int> q;
  vector<vector<int> > v(m);
  vector<vector<int> > u(n + 2);
  for (int i = 0; i < m; i++) {
    cin >> k;
    for (int j = 0; j < k; j++) {
      cin >> a;
      v[i].push_back(a);
    }
    reverse(v[i].begin(), v[i].end());
  }
  for (int i = 0; i < m; i++) {
    u[v[i].back()].push_back(i);
    if (u[v[i].back()].size() == 2) {
      q.push(v[i].back());
    }
    v[i].pop_back();
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (int l = 0; l < 2; l++) {
        int y = u[x][l];
        if (!v[y].empty()) {
          u[v[y].back()].push_back(y);
          if (u[v[y].back()].size() == 2) {
            q.push(v[y].back());
          }
          v[y].pop_back();
        }
      }
      u[x].clear();
    }
  }
  for (int i = 0; i < m; i++) {
    if (!v[i].empty()) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}