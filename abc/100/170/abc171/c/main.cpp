#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main() {
  ll n;
  cin >> n;
  string s = "", t = "zabcdefghijklmnopqrstuvwxyz";
  while (n) {
    s += t.substr((n % 26LL), 1);
    if (n % 26LL) {
      n -= n % 26LL;
    } else {
      n -= 26LL;
    }
    n /= 26LL;
  }
  reverse(s.begin(), s.end());
  cout << s << endl;
}