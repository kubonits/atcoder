#include <cmath>
#include <iostream>
using namespace std;
int main() {
  int n, p[8], q[8], f[8] = {}, fq[8] = {}, a = 0, b = 0;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> p[i];
    int cnt = 0;
    p[i]--;
    for (int j = 0; j < p[i]; j++) {
      if (f[j] == 0) {
        cnt++;
      }
    }
    a += cnt;
    a *= (n - 1 - i);
    f[p[i]] = 1;
  }
  cin >> p[n - 1];
  for (int i = 0; i < n - 1; i++) {
    cin >> q[i];
    q[i]--;
    int cnt = 0;
    for (int j = 0; j < q[i]; j++) {
      if (fq[j] == 0) {
        cnt++;
      }
    }
    b += cnt;
    b *= (n - 1 - i);
    fq[q[i]] = 1;
  }
  cin >> q[n - 1];
  cout << abs(a - b) << endl;
}