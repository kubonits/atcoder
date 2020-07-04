#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  ll d, c[26], s[365][26], t[365], ans = 0, m, x, y, v, old[2];
  ll ra[100000];
  for (int i = 0; i < 100000; i++) {
    ra[i] = (floor(20 / (log(i % 100000 + 20) / log(20)))) - 4;
  }
  set<ll> se[26];
  srand(time(NULL));
  cin >> d;
  for (int i = 0; i < 26; i++) {
    cin >> c[i];
    se[i].insert(0);
    se[i].insert(d + 1);
  }
  for (int i = 0; i < d; i++) {
    for (int j = 0; j < 26; j++) {
      cin >> s[i][j];
    }
  }
  for (int i = d - 1; i >= 0; i--) {
    x = -10000000000000;
    y = -1;
    for (int j = 0; j < 26; j++) {
      set<ll>::iterator it = se[j].lower_bound(i + 1);
      it--;
      if (x < s[i][j] + (*se[j].lower_bound(i + 1) - (i + 1)) * c[j] *
                            (i + 1 - *it)) {
        y = j;
        x = s[i][j] +
            (*se[j].lower_bound(i + 1) - (i + 1)) * c[j] * (i + 1 - *it);
      }
    }
    t[i] = y;
    se[t[i]].insert(i + 1);
    ans += s[i][t[i]];
    for (int j = 0; j < 26; j++) {
      ans -= (i + 1 - *se[j].rbegin()) * c[j];
    }
  } /*
   for (int i = 0; i < 26; i++) {
     se[i].insert(d + 1);
   }*/
  for (int i = 0; i < 4800000; i++) {
    y = ra[rand() % 100000];
    x = rand() % (d - y) + 1;
    y += x;
    v = 0LL;
    v += s[x - 1][t[y - 1]] - s[x - 1][t[x - 1]] + s[y - 1][t[x - 1]] -
         s[y - 1][t[y - 1]];
    set<ll>::iterator it = se[t[x - 1]].find(x);
    it--;
    ll z = *se[t[x - 1]].upper_bound(x);
    v -= c[t[x - 1]] * (z - x) * (x - *it);
    se[t[x - 1]].erase(x);
    it = se[t[y - 1]].find(y);
    it--;
    z = *se[t[y - 1]].upper_bound(y);
    v -= c[t[y - 1]] * (z - y) * (y - *it);
    se[t[y - 1]].erase(y);
    it = se[t[y - 1]].lower_bound(x);
    it--;
    v += c[t[y - 1]] * (*se[t[y - 1]].lower_bound(x) - x) * (x - *it);
    it = se[t[x - 1]].lower_bound(y);
    it--;
    v += c[t[x - 1]] * (*se[t[x - 1]].lower_bound(y) - y) * (y - *it);
    if (v > 0LL) {
      ans += v;
      se[t[x - 1]].insert(y);
      se[t[y - 1]].insert(x);
      ll temp = t[x - 1];
      t[x - 1] = t[y - 1];
      t[y - 1] = temp;
    } else {
      se[t[x - 1]].insert(x);
      se[t[y - 1]].insert(y);
    }
  }
  for (int i = 0; i < d; i++) {
    cout << t[i] + 1 << endl;
  }
}