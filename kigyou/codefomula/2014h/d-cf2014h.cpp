#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
  int n, m, s, e;
  ll h[3000], maxi[6001] = {}, sh[3001] = {}, ans = 0;
  vector<pair<pair<int, int>, int> > p;
  vector<int> v;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &h[i]);
  }
  for (int i = 0; i < n; i++) {
    sh[i + 1] = sh[i] + h[i];
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &m, &s, &e);
    v.push_back(s);
    v.push_back(e);
    p.push_back({{e, s}, m});
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < v.size(); j++) {
      if (p[i].first.first == v[j]) {
        p[i].first.first = j;
      }
      if (p[i].first.second == v[j]) {
        p[i].first.second = j;
      }
    }
  }
  sort(p.begin(), p.end());
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= p[i].first.second; j++) {
      maxi[j] = max(maxi[j], maxi[j - 1]);
    }
    maxi[p[i].first.first] =
        max(maxi[p[i].first.first], maxi[p[i].first.second] + h[0]);
    int cnt = 1;
    int x = p[i].first.first;
    for (int j = i + 1; j < n; j++) {
      if (p[i].second == p[j].second && x <= p[j].first.second) {
        cnt++;
        maxi[p[j].first.first] =
            max(maxi[p[j].first.first], maxi[p[i].first.second] + sh[cnt]);
        x = p[j].first.first;
      }
    }
  }
  for (int j = 0; j <= p[n - 1].first.first; j++) {
    ans = max(ans, maxi[j]);
  }
  printf("%lld\n", ans);
}