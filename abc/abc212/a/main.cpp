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
  int a, b;
  cin >> a >> b;
  if (!b) {
    cout << "Gold" << endl;
  } else {
    cout << (a == 0 ? "Silver" : "Alloy") << endl;
  }
}