#include <iostream>
#include <string>
using namespace std;
int main() {
  string s;
  cin >> s;
  cout << s.substr(0, s.length() - 1) + "5" << endl;
}