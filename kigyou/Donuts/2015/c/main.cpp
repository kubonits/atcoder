#include <iostream>
#include <set>
using namespace std;

int h[100000], sum[100010], p[1000001];
int main() {
  int n;
  set<int> s;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> h[i];
    p[h[i]] = i + 1;
  }
  for (int i = 1000000; i > 0; i--) {
    if (p[i]) {
      sum[p[i]] += 1;
      set<int>::iterator it = s.upper_bound(p[i]);
      if (it != s.end()) {
        sum[*it]--;
      }
      s.insert(p[i]);
    }
  }
  for (int i = 1; i <= n; i++) {
    sum[i] += sum[i - 1];
  }
  for (int i = 0; i < n; i++) {
    cout << sum[i] << endl;
  }
}