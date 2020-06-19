#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

ll calc(string s, ll m) {
  ll res = 0LL;
  for (int i = 0; i < s.length(); i++) {
    res *= m;
    res += s[i] - '0';
  }
  return res;
}

int main() {
  ll n;
  string s;
  cin >> n >> s;
  for (int i = 2; i <= 10; i++) {
    if (n == calc(s, i)) {
      cout << i << endl;
      return 0;
    }
  }
}