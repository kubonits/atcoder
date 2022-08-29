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
  string n;
  cin >> n;
  cout << (n[0] == n[1] && n[0] == n[2] ? "Won" : "Lost") << endl;
}
