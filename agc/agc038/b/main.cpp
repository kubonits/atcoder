#include <iostream>
using namespace std;
#define MAX_N 200001
int n, k;
int a[MAX_N];

int b[MAX_N];
int c[MAX_N];
int d[MAX_N];
int deq[MAX_N];
void solve() {
  int s = 0, t = 0;  //デックの先頭と末尾

  for (int i = 0; i < n; i++) {
    //デックにiを追加
    while (s < t && a[deq[t - 1]] >= a[i]) t--;
    deq[t++] = i;

    if (i - k + 1 >= 0) {
      b[i - k + 1] = a[deq[s]];

      if (deq[s] == i - k + 1) {
        //デックの先頭を取り出す
        s++;
      }
    }
  }
}

void solve2() {
  int s = 0, t = 0;  //デックの先頭と末尾

  for (int i = 0; i < n; i++) {
    //デックにiを追加
    while (s < t && a[deq[t - 1]] <= a[i]) t--;
    deq[t++] = i;

    if (i - k + 1 >= 0) {
      c[i - k + 1] = a[deq[s]];

      if (deq[s] == i - k + 1) {
        //デックの先頭を取り出す
        s++;
      }
    }
  }
}

int main() {
  int ans = 0, flag = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  solve();
  solve2();
  d[0] = 1;
  for (int i = 1; i < n; i++) {
    if (a[i] > a[i - 1]) {
      d[i] = d[i - 1] + 1;
    } else {
      d[i] = 1;
    }
  }
  ans = 1;
  for (int i = 1; i <= n - k; i++) {
    ans++;
    if (a[i - 1] < b[i] && c[i] == a[i + k - 1] || flag && d[i + k - 1] >= k) {
      ans--;
    }
    if (d[i + k - 1] >= k) {
      flag = 1;
    }
  }
  cout << ans << endl;
}