#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
  int n, m, a, b;
  cin >> n >> m;
  vector<int> p(n + 1);
  vector<vector<int> > v(n + 1);
  queue<int> q;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for (int i = 2; i <= n; i++) {
    p[i] = -1;
  }
  p[1] = 1;
  q.push(1);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = 0; i < v[x].size(); i++) {
      if (p[v[x][i]] == -1) {
        p[v[x][i]] = x;
        q.push(v[x][i]);
      }
    }
  }
  cout << "Yes" << endl;
  for (int i = 2; i <= n; i++) {
    cout << p[i] << endl;
  }
}