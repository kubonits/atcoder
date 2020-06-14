#include <iostream>
#include <vector>
using namespace std;
vector<int> v[100001];
int main() {
  int n, a, ans = 1, p = -1, b;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    v[a].push_back(i);
  }
  for (int i = 1; i <= 100000; i++) {
    if (!v[i].empty()) {
      b = v[i].back();
      while (!v[i].empty() && v[i].back() > p) {
        v[i].pop_back();
      }
      if (!v[i].empty()) {
        p = v[i].back();
        ans++;
      } else {
        p = b;
      }
    }
  }
  if (p == 0) {
    ans--;
  }
  cout << ans << endl;
}