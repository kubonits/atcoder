#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int a[200000], visited[200000];

ll dfs(int x, int y) {
  ll res = 0LL;
  while (a[x] != y) {
    x = a[x];
    res++;
  }
  return res + 1LL;
}

int main() {
  int n, p = 0, pp;
  ll k, cnt = 0LL;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  while (k && visited[p] == 0) {
    visited[p] = 1;
    p = a[p];
    k--;
  }
  if (k == 0 || a[p] == p) {
    cout << p + 1LL << endl;
    return 0;
  }
  cnt = dfs(p, p);
  k %= cnt;
  for (ll i = 0; i < k; i++) {
    p = a[p];
  }
  cout << p + 1LL << endl;
}