#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
  vector<string> v;
  for (int i = 1; i <= 1000; i++) {
    v.push_back(to_string(i));
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < 1000; i++) {
    cout << v[i] << endl;
  }
}