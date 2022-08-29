#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
  int n;
  string s;
  vector<string> v;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    reverse(s.begin(), s.end());
    v.push_back(s);
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    reverse(v[i].begin(), v[i].end());
    cout << v[i] << endl;
  }
}