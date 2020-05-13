#include <iostream>
#include <map>
#include <utility>
using namespace std;
int sum[100010], r[100000], h[100000];
int main() {
  int n;
  map<pair<int, int>, int> m;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> r[i] >> h[i];
    sum[r[i]]++;
    if (m.find({r[i], h[i]}) == m.end()) {
      m.insert({{r[i], h[i]}, 1});
    } else {
      m[{r[i], h[i]}]++;
    }
  }
  for (int i = 99999; i >= 0; i--) {
    sum[i] += sum[i + 1];
  }
  for (int i = 0; i < n; i++) {
    int w = n - sum[r[i]];
    int l = sum[r[i] + 1];
    int d = m[{r[i], h[i]}] - 1;
    for (int j = 1; j <= 3; j++) {
      if ((3 + h[i] - j) % 3 == 1 && m.find({r[i], j}) != m.end()) {
        l += m[{r[i], j}];
      } else if ((3 + h[i] - j) % 3 == 2 && m.find({r[i], j}) != m.end()) {
        w += m[{r[i], j}];
      }
    }
    cout << w << " " << l << " " << d << endl;
  }
}