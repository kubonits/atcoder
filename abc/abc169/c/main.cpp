#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
  ll n, x = 0LL;
  string s;
  cin >> n >> s;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] != '.') {
      x *= 10;
      x += s[i] - '0';
    }
  }
  cout << n * x / 100 << endl;
}