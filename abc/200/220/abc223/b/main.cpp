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
  string s, mini, maxi;
  cin >> s;
  mini = maxi = s;
  for (int i = 0; i < s.length(); i++) {
    mini = min(mini, s.substr(i) + s.substr(0, i));
    maxi = max(maxi, s.substr(i) + s.substr(0, i));
  }
  cout << mini << endl;
  cout << maxi << endl;
}
