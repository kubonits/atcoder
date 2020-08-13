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
  int n, s, t, ans = 0;
  cin >> n >> s >> t;
  while (t > s) {
    t /= 2;
    ans++;
  }
  cout << (s == t ? ans : -1) << endl;
}