#include <algorithm>
#include <cmath>
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

int main() {
  int n;
  string s;
  map<string, int> m;
  cin >> n;
  m.insert({"AC", 0});
  m.insert({"WA", 0});
  m.insert({"TLE", 0});
  m.insert({"RE", 0});
  for (int i = 0; i < n; i++) {
    cin >> s;
    m[s]++;
  }
  cout << "AC x " << m["AC"] << endl;
  cout << "WA x " << m["WA"] << endl;
  cout << "TLE x " << m["TLE"] << endl;
  cout << "RE x " << m["RE"] << endl;
}