#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
int main() {
  int n, sum[4] = {}, maxi = 0, mini = 1000;
  string s;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    sum[s[i] - '1']++;
    maxi = max(maxi, sum[s[i] - '1']);
  }
  mini = min(sum[0], sum[1]);
  mini = min(mini, sum[2]);
  mini = min(mini, sum[3]);
  cout << maxi << " " << mini << endl;
}