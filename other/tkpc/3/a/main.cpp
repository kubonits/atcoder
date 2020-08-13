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
  char c, d;
  cin >> c >> a >> d >> b;
  cout << (c == d ? abs(a - b) / 15 : (a + b) / 15) << endl;
}