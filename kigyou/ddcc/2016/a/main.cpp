#include <iostream>
#include <string>

using namespace std;
int main() {
  string s = "DiscoPresentsDiscoveryChannelProgrammingContest2016";
  int n;
  cin >> n;
  for (int i = 0; i < s.length(); i++) {
    cout << s[i];
    if (i % n == n - 1) {
      cout << endl;
    }
  }
  if (s.length() % n) {
    cout << endl;
  }
}