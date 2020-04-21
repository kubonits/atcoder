#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n;
  map<string, string> m;
  string s;
  vector<string> v;
  m.insert({"b", "1"});
  m.insert({"c", "1"});
  m.insert({"d", "2"});
  m.insert({"w", "2"});
  m.insert({"t", "3"});
  m.insert({"j", "3"});
  m.insert({"f", "4"});
  m.insert({"q", "4"});
  m.insert({"l", "5"});
  m.insert({"v", "5"});
  m.insert({"s", "6"});
  m.insert({"x", "6"});
  m.insert({"p", "7"});
  m.insert({"m", "7"});
  m.insert({"h", "8"});
  m.insert({"k", "8"});
  m.insert({"n", "9"});
  m.insert({"g", "9"});
  m.insert({"z", "0"});
  m.insert({"r", "0"});
  m.insert({"B", "1"});
  m.insert({"C", "1"});
  m.insert({"D", "2"});
  m.insert({"W", "2"});
  m.insert({"T", "3"});
  m.insert({"J", "3"});
  m.insert({"F", "4"});
  m.insert({"Q", "4"});
  m.insert({"L", "5"});
  m.insert({"V", "5"});
  m.insert({"S", "6"});
  m.insert({"X", "6"});
  m.insert({"P", "7"});
  m.insert({"M", "7"});
  m.insert({"H", "8"});
  m.insert({"K", "8"});
  m.insert({"N", "9"});
  m.insert({"G", "9"});
  m.insert({"Z", "0"});
  m.insert({"R", "0"});
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    string x = "";
    for (int j = 0; j < s.length(); j++) {
      if (m.find(s.substr(j, 1)) != m.end()) {
        x += m[s.substr(j, 1)];
      }
    }
    if (x.length() > 0) {
      v.push_back(x);
    }
  }
  for (int i = 0; i < v.size(); i++) {
    cout << v[i];
    if (i != v.size() - 1) {
      cout << " ";
    }
  }
  cout << endl;
}