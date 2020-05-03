#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, a, b, visited[100001], x;
int main() {
  vector<int> v[100001], ans;
  priority_queue<int, vector<int>, greater<int> > q;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  q.push(1);
  while (!q.empty()) {
    x = q.top();
    q.pop();
    ans.push_back(x);
    visited[x] = 1;
    for (int i = 0; i < v[x].size(); i++) {
      if (visited[v[x][i]] == 0) {
        q.push(v[x][i]);
      }
    }
  }
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i];
    if (i != ans.size() - 1) {
      cout << " ";
    }
  }
  cout << endl;
}