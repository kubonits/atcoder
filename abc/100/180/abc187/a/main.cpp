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
  int n, m;
  cin >> n >> m;
  cout << max(n / 100 + n / 10 % 10 + n % 10, m / 100 + m / 10 % 10 + m % 10)
       << endl;
}
