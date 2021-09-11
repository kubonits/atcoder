#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
  int n, maxi = 0;
  map<string, int> m;
  string s;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (m.find(s) != m.end()) {
      m[s]++;
      maxi = max(maxi, m[s]);
    } else {
      m.insert({s, 1});
      maxi = max(maxi, 1);
    }
  }
  map<string, int>::iterator it = m.begin();
  while (it != m.end()) {
    if (it->second == maxi) {
      cout << it->first << endl;
    }
    it++;
  }
}