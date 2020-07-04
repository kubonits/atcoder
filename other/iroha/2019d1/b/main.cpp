#include <iostream>
#include <string>
using namespace std;
int main() {
  int k;
  string s;
  cin >> s >> k;
  for (int i = 0; i < k; i++) {
    s = s.substr(1) + s.substr(0, 1);
  }
  cout << s << endl;
}