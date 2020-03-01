#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <utility>
#include <vector>
using namespace std;

char s[500001];
int main() {
  int n, q, x, l, r;
  char c[5];
  set<int> se[26];
  scanf("%d", &n);
  scanf("%s", s);
  scanf("%d", &q);
  for (int i = 0; i < n; i++) {
    se[s[i] - 'a'].insert(i);
  }
  for (int i = 0; i < q; i++) {
    scanf("%d", &x);
    if (x == 1) {
      scanf("%d %s", &l, c);
      l--;
      se[s[l] - 'a'].erase(l);
      se[c[0] - 'a'].insert(l);
      s[l] = c[0];
    } else {
      scanf("%d%d", &l, &r);
      l--;
      r--;
      int ans = 0;
      for (int j = 0; j < 26; j++) {
        set<int>::iterator it = se[j].lower_bound(l);
        if (it != se[j].end() && *it <= r) {
          ans++;
        }
      }
      printf("%d\n", ans);
    }
  }
}