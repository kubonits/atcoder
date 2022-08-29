#include <algorithm>
#include <climits>
#include <cstdio>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
const int MAX_N = 1 << 17;

ll dat[2 * MAX_N - 1];
int n;

void init(int n_) {
  n = 1;
  while (n < n_) {
    n *= 2;
  }
  for (int i = 0; i < 2 * n - 1; i++) {
    dat[i] = 1000000000000;
  }
}

void update(int k, ll a) {
  k += n - 1;
  dat[k] = a;
  while (k > 0) {
    k = (k - 1) / 2;
    dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
  }
}

ll query(int a, int b, int k, int l, int r) {
  if (r <= a || b <= l) {
    return 1000000000000;
  }
  if (a <= l && r <= b) {
    return dat[k];
  } else {
    ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
    ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
    return min(vl, vr);
  }
}

int main() {
  int L, l, r, LL;
  ll c;
  vector<pair<pair<int, int>, ll> > v;
  scanf("%d%d", &L, &n);
  LL = n;
  for (int i = 0; i < L; i++) {
    scanf("%d%d%lld", &l, &r, &c);

    v.push_back({{l, r}, c});
  }
  sort(v.begin(), v.end());
  init(n + 2);
  update(0, 0);

  for (int i = 0; i < L; i++) {
    ll a = min(
        query(v[i].first.second, v[i].first.second + 1, 0, 0, n),
        query(v[i].first.first, v[i].first.second + 1, 0, 0, n) + v[i].second);

    update(v[i].first.second, a);
  }

  printf("%lld\n", query(LL, LL + 1, 0, 0, n));
}