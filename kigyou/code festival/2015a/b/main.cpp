#include <iostream>
using namespace std;

typedef long long ll;

int main() {
  int n;
  ll a[30], b[31];
  cin >> n;
  b[0] = 0LL;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i + 1] = 2LL * b[i] + a[i];
  }
  cout << b[n] << endl;
}