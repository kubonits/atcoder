#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int n, a, b, p;
ll sum, c[100000], d[100000], maxi;
vector<int> v[100000];

void dfs(int x, int y) {
  d[x] = c[p];
  p--;
  for (int i = 0; i < v[x].size(); i++) {
    if (v[x][i] != y) {
      dfs(v[x][i], x);
    }
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    a--;
    b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    sum += c[i];
    maxi = max(maxi, c[i]);
  }
  sum -= maxi;
  sort(c, c + n);
  p = n - 1;
  dfs(0, -1);
  cout << sum << endl;
  for (int i = 0; i < n; i++) {
    cout << d[i] << " ";
  }
  cout << endl;
}