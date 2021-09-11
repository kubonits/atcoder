#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;
typedef long long ll;
int main() {
  ll n, a, b;
  cin >> a >> b >> n;
  cout << a * min(n, b - 1LL) / b - a * (min(n, b - 1LL) / b) << endl;
}