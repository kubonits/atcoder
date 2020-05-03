#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;
int main() {
  ll n, sum = 1LL;
  cin >> n;
  if (n == 1LL) {
    cout << "Deficient" << endl;
    return 0;
  }
  for (ll i = 2LL; i <= sqrt(n); i++) {
    if (n % i == 0) {
      sum += i;
      if (i * i != n) {
        sum += n / i;
      }
    }
    if (sum > n) {
      cout << "Abundant" << endl;
      return 0;
    }
  }
  if (sum == n) {
    cout << "Perfect" << endl;
  } else {
    cout << "Deficient" << endl;
  }
}