#include <algorithm>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
ll lr[4010], rr[4010], lg[4010], rg[4010], lb[4010], rb[4010];
int main() {
  ll n;
  char s[4010];
  ll ans = 0LL;
  scanf("%lld", &n);
  scanf("%s", s);
  for (int i = 0; i < n; i++) {
    lr[i + 1] = lr[i];
    lg[i + 1] = lg[i];
    lb[i + 1] = lb[i];
    if (s[i] == 'R') {
      lr[i + 1]++;
    }
    if (s[i] == 'G') {
      lg[i + 1]++;
    }
    if (s[i] == 'B') {
      lb[i + 1]++;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    rr[i] = rr[i + 1];
    rg[i] = rg[i + 1];
    rb[i] = rb[i + 1];
    if (s[i] == 'R') {
      rr[i]++;
    }
    if (s[i] == 'G') {
      rg[i]++;
    }
    if (s[i] == 'B') {
      rb[i]++;
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 1; i + j < n - 1; j++) {
      if (s[i] == 'R') {
        if (s[i + j] == 'G') {
          ans += rb[i + j];
          if (i + 2 * j < n && s[i + 2 * j] == 'B') {
            ans--;
          }
        }
        if (s[i + j] == 'B') {
          ans += rg[i + j];
          if (i + 2 * j < n && s[i + 2 * j] == 'G') {
            ans--;
          }
        }
      } else if (s[i] == 'G') {
        if (s[i + j] == 'R') {
          ans += rb[i + j];
          if (i + 2 * j < n && s[i + 2 * j] == 'B') {
            ans--;
          }
        }
        if (s[i + j] == 'B') {
          ans += rr[i + j];
          if (i + 2 * j < n && s[i + 2 * j] == 'R') {
            ans--;
          }
        }
      } else if (s[i] == 'B') {
        if (s[i + j] == 'G') {
          ans += rr[i + j];
          if (i + 2 * j < n && s[i + 2 * j] == 'R') {
            ans--;
          }
        }
        if (s[i + j] == 'R') {
          ans += rg[i + j];
          if (i + 2 * j < n && s[i + 2 * j] == 'G') {
            ans--;
          }
        }
      }
    }
  }
  printf("%lld\n", ans);
}