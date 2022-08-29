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
  int v, t, s, d;
  cin >> v >> t >> s >> d;
  cout << (v * t > d || d > v * s ? "Yes" : "No") << endl;
}
