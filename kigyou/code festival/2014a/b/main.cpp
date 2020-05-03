#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  string s;
  cin >> s >> n;
  n--;
  cout << s[n % s.length()] << endl;
}