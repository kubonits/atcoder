#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  vector<string> v;
  string s;
  for (int i = 0; i < 15; i++) {
    cin >> s;
    v.push_back(s);
  }
  sort(v.begin(), v.end());
  cout << v[6] << endl;
}