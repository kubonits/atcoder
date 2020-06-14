#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  int n;
  map<string, int> m;
  string s;
  m.insert({"black", 0});
  m.insert({"white", 0});
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    m[s]++;
  }
  if (m["white"] > m["black"]) {
    cout << "white" << endl;
  } else {
    cout << "black" << endl;
  }
}