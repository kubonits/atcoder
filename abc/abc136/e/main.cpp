#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int n, k, a[500], sum = 0, b[500], ans = 1;
  vector<int> v;
  pair<int, int> l, r;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  for (int i = 1; i * i <= sum; i++) {
    if (sum % i == 0) {
      v.push_back(i);
      if (i != sum / i) {
        v.push_back(sum / i);
      }
    }
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < n; j++) {
      b[j] = a[j] % v[i];
    }
    sort(b, b + n);
    l = {0, 0};
    r = {n - 1, 0};
    while (l.first < r.first) {
      if (b[l.first] == b[r.first] && b[l.first] == 0) {
        l.first++;
        r.first--;
      } else if (b[l.first] == 0) {
        l.first++;
      } else if (l.second == r.second) {
        l.second += b[l.first];
        r.second += v[i] - b[r.first];
        l.first++;
        r.first--;
      } else if (l.second < r.second) {
        l.second += b[l.first];
        l.first++;
      } else {
        r.second += v[i] - b[r.first];
        r.first--;
      }
    }
    if (l.second <= k && l.first == r.first && b[l.first] == 0) {
      ans = v[i];
    }
    if (l.second <= k && l.first > r.first && l.second == r.second) {
      ans = v[i];
    }
    if (l.first == r.first &&
        (l.second <= k && l.second == r.second + v[i] - b[r.first] ||
         l.second + b[l.first] <= k && l.second + b[l.first] == r.second)) {
      ans = v[i];
    }
  }
  cout << ans << endl;
}