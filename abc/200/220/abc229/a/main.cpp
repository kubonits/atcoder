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
#define MOD2 998244353
using namespace std;
typedef long long ll;
#include <cstring>

int main() {
  string s, t;
  cin >> s >> t;
  cout << (s == "#." && t == ".#" || s == ".#" && t == "#." ? "No" : "Yes")
       << endl;
}
