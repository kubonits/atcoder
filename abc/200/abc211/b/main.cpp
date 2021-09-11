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
  string s;
  set<string> se;
  for (int i = 0; i < 4; i++) {
    cin >> s;
    se.insert(s);
  }
  cout << (se.size() == 4 ? "Yes" : "No") << endl;
}