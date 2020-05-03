#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int b[101] = {}, n, a, mini = 100, maxi = 0, cnt = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    b[a]++;
    if (b[a] >= 3) {
      cnt++;
    }
    mini = min(mini, a);
    maxi = max(maxi, a);
  }

  if (mini != (maxi + 1) / 2) {
    cout << "Impossible" << endl;
    return 0;
  }
  if (maxi % 2 == 0 && b[mini] >= 2 || b[mini] >= 3) {
    cout << "Impossible" << endl;
    return 0;
  }
  if (n - cnt != maxi + 1) {
    cout << "Impossible" << endl;
    return 0;
  }
  for (int i = mini; i <= maxi; i++) {
    if (!(b[i] >= 2 || i == mini && maxi % 2 == 0)) {
      cout << "Impossible" << endl;
      return 0;
    }
  }
  cout << "Possible" << endl;
}