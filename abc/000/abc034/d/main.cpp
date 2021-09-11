#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, k;
  double w[1000], p[1000], l, r, mid, sum;
  vector<double> v;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> w[i] >> p[i];
  }
  l = 0.0;
  r = 100.0;
  for (int i = 0; i < 200; i++) {
    v.clear();
    sum = 0.0;
    mid = (l + r) / 2.0;
    for (int j = 0; j < n; j++) {
      v.push_back(w[j] * (p[j] - mid));
    }
    sort(v.begin(), v.end());
    for (int j = 0; j < k; j++) {
      sum += v[n - 1 - j];
    }
    if (sum >= 0) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << fixed << setprecision(9) << (l + r) / 2.0 << endl;
}