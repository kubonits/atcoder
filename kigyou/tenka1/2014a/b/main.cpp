#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
int a[1000010];
ll c[1000010];
int main() {
  long long sum = 0LL;
  int n, k = 5;
  string s;
  cin >> s;
  n = s.length();
  s += "--";
  for (int i = 0; i < n; i++) {
    k += a[i];
    if (s[i] == 'N' && k >= 1) {
      sum += 10LL;
      c[i + 2]++;
      k--;
      a[i + 7] += 1;
      sum += c[i] / 10LL;
    }
    if (s[i] == 'C' && k >= 3) {
      sum += 50LL;
      c[i + 4]++;
      k -= 3;
      a[i + 9] += 3;
      s[i + 1] = '-';
      s[i + 2] = '-';
      sum += c[i] / 10LL * 5LL;
    }
    c[i + 1] += c[i];
  }
  cout << sum << endl;
}