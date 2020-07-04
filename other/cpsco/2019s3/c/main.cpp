#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, s, t, ans = 0;
  vector<int> v(1000001);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s >> t;
    v[s]++;
    v[t]--;
  }
  for (int i = 1; i <= 1000000; i++) {
    v[i] += v[i - 1];
    if (!v[i - 1] && v[i]) {
      ans++;
    }
  }
  cout << ans << endl;
}