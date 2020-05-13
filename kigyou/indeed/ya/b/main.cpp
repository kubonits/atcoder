#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
  int n;
  string s, t = "indeednow";
  sort(t.begin(), t.end());
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    sort(s.begin(), s.end());
    if (s == t) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}