#include <algorithm>
#include <cmath>
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
  cin >> n;
  string s;
  map<string, string> m;
  m.insert({"Mon", "Tue"});
  m.insert({"Tue", "Wed"});
  m.insert({"Wed", "Thu"});
  m.insert({"Thu", "Fri"});
  m.insert({"Fri", "Sat"});
  m.insert({"Sat", "Sun"});
  m.insert({"Sun", "Mon"});
  for (int i = 0; i < n; i++) {
    cin >> s;
    cout << m[s] << endl;
  }
}