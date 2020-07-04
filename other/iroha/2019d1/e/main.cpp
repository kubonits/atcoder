#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
ll n, a, b, d[200000], p = 0LL, sum = 0LL;
int main() {
  cin >> n >> a >> b;
  for (int i = 0; i < b; i++) {
    cin >> d[i];
  }
  sort(d, d + b);
  for (int i = 0; i < b; i++) {
    sum += (d[i] - p) / a;
    if ((d[i] - p) % a) {
      sum++;
    }
    p = d[i];
  }
  sum += (n - p) / a;
  cout << n - sum << endl;
}