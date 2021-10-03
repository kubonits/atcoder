#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
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
#include <cstring>

int main() {
  vector<int> v(1000001);
  set<int> s;
  for (int i = 2; i <= 1000000; i++) {
    v[i] = 1;
  }
  for (ll i = 2LL; i <= 1000000LL; i++) {
    if (v[i] == 1) {
      s.insert(i);
      for (ll j = i * i; j <= 1000000; j += i) {
        v[j] = 0;
      }
    }
  }
  cout << *s.rbegin() << endl;
}