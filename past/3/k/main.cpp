#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;
int head[200001], bottom[200001], parent[200001], childe[200001], ans[200001];
int main() {
  int n, q, f, t, x;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    head[i] = bottom[i] = i;
    parent[i] = childe[i] = -1;
  }
  for (int i = 0; i < q; i++) {
    cin >> f >> t >> x;
    if (bottom[f] == x) {
      bottom[f] = -1;
    }
    if (bottom[t] == -1) {
      bottom[t] = x;
    }
    int Head = head[f];
    head[f] = childe[x];
    parent[childe[x]] = -1;
    childe[x] = head[t];
    parent[head[t]] = x;
    head[t] = Head;
  }
  for (int i = 1; i <= n; i++) {
    if (bottom[i] != -1) {
      int x = bottom[i];
      ans[x] = i;
      while (parent[x] != -1) {
        x = parent[x];
        ans[x] = i;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << endl;
  }
}