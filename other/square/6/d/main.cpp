#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
double x[100000], r[100000], ans = 0.0, s = 0.0, suml[100000], sumr[100000];
int main() {
  int n;

  vector<pair<double, double> > v;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> r[i];
    v.push_back({x[i], r[i]});
  }
  sort(v.begin(), v.end());
  ans = s = v[0].second;
  suml[0] = v[0].second;
  for (int i = 1; i < n; i++) {
    s = pow((pow(max(0.0, s - (v[i].first - v[i - 1].first)), 3.0) +
             pow(v[i].second, 3.0)),
            1.0 / 3.0);
    ans = max(ans, s);
    suml[i] = s;
  }
  s = v[n - 1].second;
  for (int i = n - 2; i >= 0; i--) {
    s = pow((pow(max(0.0, s - (v[i + 1].first - v[i].first)), 3.0) +
             pow(v[i].second, 3.0)),
            1.0 / 3.0);
    ans = max(ans, s);
    sumr[i] = s;
  }
  for (int i = 0; i < n - 1; i++) {
    ans = max(
        ans,
        pow(pow(suml[i], 3.0) +
                pow(max(0.0, sumr[i + 1] - (v[i + 1].first - v[i].first)), 3.0),
            1.0 / 3.0));
  }
  for (int i = n - 1; i > 0; i--) {
    ans = max(
        ans,
        pow(pow(sumr[i], 3.0) +
                pow(max(0.0, suml[i - 1] - (v[i].first - v[i - 1].first)), 3.0),
            1.0 / 3.0));
  }
  cout << ans << endl;
}